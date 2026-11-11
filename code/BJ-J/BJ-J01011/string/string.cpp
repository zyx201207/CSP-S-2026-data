#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200000;//2e5
char c[N+10];
int a[N+10];//1e9
int main(){
    // freopen("string6.in","r",stdin);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;//2e5
    cin>>n;
    ll sum=0;//2e14
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        sum+=a[i];
    }
    ll si=0,sj=0,ans=0;//2e14 2e14 1e14
    for(int i=1,j=n;si<sum/2;i++){
        si=min(si+a[i],sum/2);
        // cout<<"i:"<<i<<" si:"<<si<<'\n';
        while(sj<si){
            ll d=si-sj;//2e14
            if(d<a[j]){
                if(c[i]!=c[j])ans+=d;
                sj+=d;
                a[j]-=d;
            }
            else{
                if(c[i]!=c[j])ans+=a[j];
                sj+=a[j];
                a[j]=0;
                j--;
            }
            // cout<<"j:"<<j<<" sj:"<<sj<<" ans:"<<ans<<'\n';
        }
    }
    cout<<ans;
    return 0;
}