#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a;
ll gcda;
ll lasta;
string s;
char c;
string x,y;
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
        cin>>a>>c;
        while(a--){
            s += c;
        }
	}
	ll k = s.size();
	ll ans = 0;
	for(int i=0;i<k/2;i++){
        if(s[i] != s[k-i-1]){
            ans++;
        }
	}
	cout<<ans;
    return 0;
}
