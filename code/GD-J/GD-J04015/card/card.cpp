#include <bits/stdc++.h>
using namespace std;
using ll= long long;
ll n,m,num[500010],have[300010],ans[300010];//num ÅÆ¶Ñ£»have Êý×Ö×´Ì¬£»ans ´ð°¸£¨¼ÆÊýÆ÷£© 
vector<ll> v;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","W",stdout);
	
	cin>>n>>m; 
	for(ll i=1;i<=n;i++){
		cin>>num[i];
	}
	for(ll i=1;i<=n;i++){
		for(ll k=1;k<=m;k++){
			have[k]=0;
		}
		for(ll j=i;j<=n;j++){
			if(!have[num[j]]){
				have[num[j]]+=1;
			}else{
				while(!v[v.size()-1]==num[j]){
					have[v[v.size()-1]]-=1;
					v.pop_back();
				}
				v.pop_back();
			}
			v.push_back(num[j]);
		}
		for(ll j=0;j<v.size();j++){
			ans[v[j]]+=1;
		}
	}
	for(ll i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
