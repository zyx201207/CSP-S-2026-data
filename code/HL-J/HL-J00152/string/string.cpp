#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn =2e5+10;
ll a[maxn],ans,L;
char c;
int n;
string k;
int main(){
   freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
       cin>>a[i];cin>>c;
       for(int j=1;j<=a[i];j++)k.push_back(c);
       L+=a[i];
    }
    k=" "+k;
   for(int i=1;i<=(L+1)/2;i++){
       if(k[i]!=k[L+1-i])ans++;
   }
   cout<<ans;
    return 0;
}
