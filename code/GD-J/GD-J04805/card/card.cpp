#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5,M=3e5+5;
ll n,m;
ll a[N],b[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int t=1;t<=n;t++){
		vector<ll> v;
		for(int i=t;i<=n;i++){
			ll l=v.size(),tp=0;
			for(int j=0;j<l;j++){
				if(a[i]==v[j]){
//					if(t==2) cout<<i<<endl;
					tp=l-j;
					break;
				}
			}
			while(tp--){
				v.pop_back();
			}
			v.push_back(a[i]);
		}
		ll l=v.size();
//		cout<<t<<endl;
		for(int j=0;j<l;j++){
//			cout<<v[j]<<" ";
			b[v[j]]++;
		}
//		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
} 
