#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s[200010];
ll n,a[200010],m;
vector<ll> v;									
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ll p=a[i];
		string u;
		while(p){
			u+=(char)(p%2+'0');
			p/=2;
		}
		reverse(u.begin(),u.end());
		s[i]=u;
	}
	for(int i=1;i<=n;i++){
		string u;
		for(int j=s[i].size();j<32;j++){
			u+='0';
		}
		s[i]=u+s[i];
	}
	for(int i=0;i<=31;i++){
		ll t=0xffffffff;
		for(int j=1;j<=n;j++){
			if(s[j][i]=='1'){
				if(v.size()==m){
					int l=-1;
					for(int k=0;k<v.size();k++){
						ll p=t;
						p|=v[k];
						p&=a[j];
						if(p>t){
							l=k;
							t=p;
						}
					}
					if(l!=-1){
						v[l]=a[j];
					}
				}else{
					v.push_back(a[j]);
					t&=a[j];
				}
			}
		}
		if(v.size()==m){
			cout<<t;
			return 0;
		}
		v.clear();
	}
	cout<<0;
	return 0;
}
