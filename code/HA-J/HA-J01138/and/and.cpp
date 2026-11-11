#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll m;
ll ans;
string s;
const ll N=2e5+5;
vector<ll>a;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	a.push_back(0);
//	getline(cin,s);
	for(ll i=1;i<=n;i++){
		ll x;
		scanf("%d",&x);
		a.push_back(x);
		
	}
//	ll len=s.size();
//	string w="";
//	for(ll i=0;i<len;i++){
//		if(isdigit(s[i])){
//			w+=s[i];
//			if(s[i+1]==' '||i==len-1){
//				a.push_back(atoi(w.c_str()));
//				w="";
//			}
//		}
//	}
	sort(a.begin(),a.end(),greater<ll>());
	ans=a[1];
	for(ll i=2;i<=m;i++)ans&=a[i];
	cout<<ans;
	return 0;
}
