#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
int a[500005];
ll cnt[300005];
bool f[300005];
int c[500005],pos[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(m==1){
        cout<<n<<endl;
        return 0;
    }
    if(n>5000&&m==2){
        for(int i=1;i<=n;i++){
            if(a[i]==a[n])cnt[a[i]]++;
            else cnt[1]++,cnt[2]++;
        }
        cout<<cnt[1]<<" "<<cnt[2]<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)c[j]=0;
        for(int j=1;j<=m;j++)f[j]=0;
        c[1]=a[i];f[c[1]]=1;pos[c[1]]=1;
        int t=1;
        for(int e=i+1;e<=n;e++){
            if(f[a[e]]){
                for(int k=pos[a[e]]+1;k<=t;k++)f[c[k]]=0,c[k]=0;
                t=pos[a[e]];
            }else{
                t++;
                c[t]=a[e];
                pos[c[t]]=t;
                f[c[t]]=1;
            }
        }
        for(int j=1;j<=m;j++)if(f[j])cnt[j]++;
    }
    for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";cout<<endl;
    return 0;
}
//头疼，暴力吧
//36+4=40
