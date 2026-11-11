#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500010],sm[500010];
vector<ll>v;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			bool flag=0;
			ll id=0;
			for(auto k:v){
				id++;
				if(k==a[j]){
					flag=1;
					break;
				}
			}
			if(flag){
				
				id=v.size()-id+1;
				while(id--){
					v.pop_back();
				}
				v.push_back(a[j]);
			}else{
				v.push_back(a[j]);
			}
		}
		for(ll k:v){
			sm[k]++;
		}
		while(v.size()){
			v.pop_back();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sm[i]<<" ";
	}
	return 0;
}
