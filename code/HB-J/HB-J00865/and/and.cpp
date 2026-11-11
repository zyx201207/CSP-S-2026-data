#include<iostream>
#include<cmath>
#include<limits.h>
#include<algorithm>
using namespace std;

const int N=2e5+5;
const int WEI_MAX=30;

const int MAN1=(1LL<<WEI_MAX)-1;
long long n,m;
struct node{
    long long idx;
    int num;
}a[N];
int ans=MAN1;

void dfs(long long x,long long idx,int num){
    if(num<=ans)return;
    if(x==m){
        ans=max(ans,num);
        return;
    }
    for(long long i=idx;i<=n;++i)dfs(x+1,i+1,num&a[i].num);
}

void guangyi(){
    //
    ans=0;
    dfs(0,1,MAN1);
    cout<<ans;
}

int tsj_list1[N];
int tsj_list2[N];

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;++i)cin>>a[i].num,a[i].idx=i;
    if(m==1){
        ans=0;
        for(long long i=1;i<=n;++i)ans=max(ans,a[i].num);
        cout<<ans;
    }
    else if(n<=2000&&m==2){
        ans=0;
        for(long long i=1;i<=n;++i){
            for(long long j=i+1;j<=n;++j){
                ans=max(ans,a[i].num&a[j].num);
            }
        }
        cout<<ans;
    }
    else if(m==n-1){
        tsj_list1[0]=MAN1;
        tsj_list2[n+1]=MAN1;
        for(long long i=1;i<=n;++i){
            if(i==1)tsj_list1[i]=a[i].num;
            else tsj_list1[i]=tsj_list1[i-1]&a[i].num;
        }
        for(long long i=n;i>=1;--i){
            if(i==n)tsj_list2[i]=a[i].num;
            else tsj_list2[i]=tsj_list2[i+1]&a[i].num;
        }
        ans=0;
        for(long long i=1;i<=n;++i)ans=max(ans,tsj_list1[i-1]&tsj_list2[i+1]);
        cout<<ans;
    }
    else if(m==n){
        for(long long i=1;i<=n;++i)ans&=a[i].num;
        cout<<ans;
    }
    else guangyi();
    cout<<"\n";
    return 0;
}