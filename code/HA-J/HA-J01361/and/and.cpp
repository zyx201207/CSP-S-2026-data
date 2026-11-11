#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	vector<ll> ve(n);
	for(int i=0;i<n;i++){
		cin>>ve[i];
	}
	ll j=1;ll a=m;
	ll s=((n-1)*n)/2;
	string sm;

	ll f=ve[0];
	while(f){
		sm+=char(f%2+'0');
		
		f/=2;
	}
	
	ll mx=LLONG_MIN;
	for(int i=0;i<s;i++){
		
		while(j<a){
			ll b=ve[j];
			
			string s;
			while(b){
				s+=char(b%2+'0');
				b/=2;
			}
			string g;
			for(int i=s.size()-1;i>=0;i--){
				if(sm[i]==s[i]){
					g+='1';
				}else{
					g+='0';
				}
			}
			sm=g;
			g="";
			j++;
		}
		ll d=0;
		cout<<sm<<endl;
		for(int i=0;i<sm.size();i++){
			if(sm[i]!='0'){
				d+=pow(i,2);
			}
    	}
    	
    	cout<<d<<endl;
    	if(d>mx){
    		mx=d;
		}
		a+=1;
		if(a>n){
			break;
		}
		j=a-m;
	}
	cout<<mx;
	return 0;
}