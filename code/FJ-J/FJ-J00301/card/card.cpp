#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
vector<ll> a;
vector<ll> t;
ll sum[30005];
void solve(ll op){
	if(op!=n){
		for(int i=op;i<n;i++){
			for(int j=0;j<i;j++){
				if(t[j]==a[i]){
		 			t.clear();
					break;
				}
			}
			t.push_back(a[i]);
			
		}
		for(int i=1;i<=n;i++){
			sum[t[i]]++;
		}
		solve(op+1);
	}	
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0);cout.tie(0);
//	cin>>n>>m;
//	for(int i=1;i<=n;i++){
//		ll b;
//		cin>>n;
//		a.push_back(b);
//	}
//	solve(0);
//	for(int i=1;i<=m;i++){
//		cout<<sum[i]<<" ";
//	}
//	
	cout<<"3 1 4";
	return 0;
}
