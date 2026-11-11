#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
const long long INF=1e12+5;
struct crystal{
    int power,num;
};
long long pre[MAXN],ch,ans,a[MAXN],n,m;
crystal c[MAXN];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    c[ch++]={a[0],1};
    for(int i=1;i<n;i++){
        if(a[i]!=a[i-1])c[ch++].power=a[i];
        c[ch-1].num++;
    }
    pre[0]=c[0].num;
    for(int i=1;i<ch;i++){
        pre[i]=pre[i-1]+c[i].num;
    }
    for(int i=ch-1;i>=0;i--){
        long long has=m,num=0;
        for(int j=i;j>=0;j--){
            long long pm=c[i].power-c[j].power;
            if(has<pm*c[j].num){
                has/=pm;
                num+=has;
                break;
            }
            else{
                has-=pm*c[j].num;
                num+=c[j].num;
            }
        }
        ans=max(ans,num);
        if(ans>=pre[i])break;
    }
    cout<<ans;
    return 0;
}
