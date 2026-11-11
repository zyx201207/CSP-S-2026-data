#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b[500010],dp[500010];
long long f(){
    int cnt=0,c[500010];
    for(int i=1;i<=n;i++){
        c[i]=a[i];
    }
    int last=c[1],ma=0;
    for(int i=2;i<=n;i++){
        last=c[i-1];
        if(c[i]==last){
            cnt++;
        }else{
            cnt=1;
        }
        ma=max(ma,cnt);
        //cout<<ma<<" ";
    }
    return ma;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++){
        b[i]=a[i+1]-a[i];//b wei mei yi zu shu ju jian de cha de da xiao
    }
    int st=1,u=m;
    for(int i=1;i<=m;i++){
        int u=i;
        for(int j=1;j<n;j++){
            b[j]=a[j+1]-a[j];
            if(b[j]<=u){
                u-=b[j];
                a[j]=a[j+1];
                b[j]=0;
            }
        }
        dp[i]=max(dp[i-1],f());
    }
    cout<<dp[m];
    return 0;
}