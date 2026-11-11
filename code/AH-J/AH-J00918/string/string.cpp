#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
ll n,maxn,a[N],ans,sum;
char c[N];
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++){
        scanf("%lld %c",&a[i],&c[i]);
        maxn=max(maxn,a[i]);
        sum+=a[i];
    }
    if(maxn<=50){
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=a[i];j++){
                s+=c[i];
            }
        }
        for(ll i=0;i<s.size()/2;i++){
            if(s[i]!=s[s.size()-1-i])ans++;
        }
        cout<<ans;
    }
    else{
        ll l=1,r=n;
        while(l<r){
            if(a[l]<a[r]){
                if(c[l]!=c[r])ans+=a[l];
                a[r]-=a[l];
                l++;
            }
            else{
                if(c[l]!=c[r])ans+=a[r];
                a[l]-=a[r];
                r--;
            }
        }
        cout<<ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
PLEASE AC!!!!!!!!
*/
