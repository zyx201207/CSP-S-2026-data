#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,pos;
int a[N],ans[N];
void solvenn(){
    int cnt[3005],p[N]={0};
    for(int i=1;i<=n;i++){ //[i,n]
        memset(cnt,0,sizeof cnt);
        pos=0;
        for(int j=i;j<=n;j++){
            while(cnt[a[j]]>0) cnt[p[pos--]]--;
            p[++pos]=a[j];
            cnt[a[j]]++;
        }
        for(int j=1;j<=pos;j++){
            ans[p[j]]++;
            //cout<<p[j]<<' ';
        }
        //cout<<endl;
    }
}
void solvem2(){
    for(int i=1;i<=n;i++){ //[i,n]
        if(a[i]==a[n]) ans[a[i]]++;
        else ans[1]++,ans[2]++;
    }
}
void solveA(){
    int d[N]={0};
    for(int i=1;i<=n;i++) d[a[i]]++;
    for(int i=1;i<=m;i++) ans[i]=ans[i-1]+d[i];
}
void solveB(){
    int new_n=0,sum=1,cnt[3005],v[N];
    pair<int,int> p[N];
    for(int i=2;i<=n+1;i++){
        if(a[i]!=a[i-1]){
            new_n++;
            a[new_n]=a[i-1];
            v[new_n]=sum;
            sum=0;
        }
        sum++;
    }
    n=new_n;
    //for(int i=1;i<=n;i++) cout<<a[i]<<' '<<v[i]<<endl;
    for(int i=1;i<=n;i++){ //[i,n]
        memset(cnt,0,sizeof cnt);
        pos=0;
        for(int j=i;j<=n;j++){
            while(cnt[a[j]]>0) cnt[p[pos--].first]--;
            p[++pos]={a[j],v[i]};
            cnt[a[j]]++;
        }
        for(int j=1;j<=pos;j++){
            ans[p[j].first]+=p[j].second;
            //cout<<p[j]<<' ';
        }
        //cout<<endl;
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    if(n<=5000) solvenn();
    else if(m<=2) solvem2();
    else if(m>100000&&n<=200000) solveA();
    else solveB();
    for(int i=1;i<=m;i++) printf("%d ",ans[i]);
    return 0;
}
