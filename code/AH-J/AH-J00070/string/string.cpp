#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ct continue
const ll N=1e5+5,inf=1e18;
ll n,a,ans,f=0;
string s,b,c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a>>s;
		ans+=a/2;
	}
	cout<<ans;
	return 0;
}
