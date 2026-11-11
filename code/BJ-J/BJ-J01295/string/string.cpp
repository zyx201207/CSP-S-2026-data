#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    ll n,s=0;
    string x="";
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i]>>c[i];
        for(int j=1; j<=a[i]; j++){
            x+=c[i];
        }
        s+=a[i];
    }
    ll ans=0;
    for(int i=0; i<(s/2); i++){
        if(x[s-i-1]!=x[i]) ans++;
    }
    cout<<ans;
	return 0;
}
