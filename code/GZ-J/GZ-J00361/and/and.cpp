//¿ÓºŒ‘∆ GZ-J00361 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first;
#define se second;
#define pb push_back;
const int N=2E5+10;
ll n,a[N],m,vis[45],ans,z=1,b[N],h;
pair<string,ll> r[N];
string er(ll n){
	string s="",z="";
	while(n){
		s+=(n%2?"1":"0");
		n/=2;
	}
	for(ll i=s.size()-1;i>=0;i--){
		z+=s[i];
	}
	return z;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	h=m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		r[i].first=er(a[i]);
		r[i].second=i;
	}
	sort(r+1,r+n+1);
	for(ll i=n;i>=1;i--){
		string z="";
		for(ll j=r[i].first.size()-1;j>=0;j--){
			z+=r[i].first[j];
		}
		for(ll j=32;j>=0;j--){
			if((z[j]=='1'&&vis[j])||(i==n)){
				m--;
				for(ll k=0;k<z.size();k++){
					if(z[k]=='1'){
						vis[k]++;
					} 
				}
				b[i]=1;
				break;
			}
		}
		if(m==0){
			break;
		}
	}
	for(ll i=1;i<=n;i++){
		if(!m){
			break;
		} 
		if(!b[i]){
			string z="";
			for(ll j=r[i].first.size()-1;j>=0;j--){
				z+=r[i].first[j];
			}
			m--;
			cout<<i<<endl;
			for(ll k=0;k<z.size();k++){
				if(z[k]=='1'){
					vis[k]++;
				} 
			}
		}
		if(!m){
			break;
		} 
	}
	for(ll i=0;i<=32;i++){
		ans+=(vis[i]==h)*z;
		z*=2;
	}
	cout<<ans<<endl;
    return 0;
}
