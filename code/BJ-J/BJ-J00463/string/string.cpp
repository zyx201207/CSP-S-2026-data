#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define ll unsigned long long
pair<ll,char> a[200005];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i].fir>>a[i].sec;
    }
    ll i=1,j=n,ans=0;
    while(i<j){
        if(a[i].sec!=a[j].sec){
            ans+=min(a[i].fir,a[j].fir);
            if(a[i].fir==a[j].fir){
                i++;
                j--;
            }
            else if(a[i].fir>a[j].fir){
                a[i].fir-=a[j].fir;
                j--;
            }
            else{
                a[j].fir-=a[i].fir;
                i++;
            }
        }
        else{
            if(a[i].fir==a[j].fir){
                i++;
                j--;
            }
            else if(a[i].fir>a[j].fir){
                a[i].fir-=a[j].fir;
                j--;
            }
            else{
                a[j].fir-=a[i].fir;
                i++;
            }
        }
    }
    cout<<ans;
    return 0;
}
