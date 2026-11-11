#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],ans,t;
bool exitt=0;
void dfs(int x,int And,int cnt){
    if(cnt==m){
        ans=max(ans,And);
        if(ans==a[n-m+1]){
            exitt=1;
        }
        return ;
    }
    if(n-x+1<m-cnt){
        return ;
    }
    if(x>n){
        return ;
    }
    if(exitt){
        return ;
    }
    if(cnt==0){
        dfs(x+1,a[x],cnt+1);
    }else{
        dfs(x+1,And&a[x],cnt+1);
    }
    dfs(x+1,And,cnt);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    bool flag1=1,flag2=1,flag3=0;
    for(int j=0;j<=25;j++){
        if(n==(1<<j)){
            flag3=1;
            break;
        }
    }
    int p=a[1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>4){
            flag2=0;
        }
        if(a[i]!=i-1){
            flag3=0;
        }
        bool c=0;
        for(int j=0;j<=25;j++){
            if(a[i]==(1<<j)-1){
                c=1;
                break;
            }
            if(a[i]<(1<<j)-1){
                break;
            }
        }
        flag1=flag1&c;
        if(i!=1){
            p=p&a[i];
        }
    }
    sort(a+1,a+n+1);
    if(flag1){
        cout<<a[n-m+1];
        return 0;
    }
    if(m==1){
        cout<<a[n];
        return 0;
    }
    if(m==n){
        cout<<p;
        return 0;
    }
    if(m==2){
        ans=0;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
        return 0;
    }
    if(flag2){
        int cnt[5]={};
        for(int i=1;i<=n;i++){
            cnt[a[i]]++;
        }
        if(cnt[4]>=m){
            cout<<4;
        }else if(cnt[3]>=m){
            cout<<3;
        }else if(cnt[2]+cnt[3]>=m){
            cout<<2;
        }else if(cnt[1]+cnt[2]+cnt[3]>=m){
            cout<<1;
        }else{
            cout<<0;
        }
        return 0;
    }
    if(flag3){
        if(m<=n/2){
            cout<<n/2;
        }else{
            cout<<0;
        }
        return 0;
    }
    dfs(1,0,0);
    cout<<ans;
    return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7

16 9
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
*/
