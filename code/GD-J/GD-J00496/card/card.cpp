#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[500010];
unordered_map<ll,ll>mp;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","r",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		vector<ll>q;
		for(int j=i;j<=n;j++){
			ll x=-1;
			for(int k=0;k<q.size();k++){
				if(a[j]==q[k]){
					x=k;
					break;	
				}
			}
			if(x==-1){
				q.push_back(a[j]);
			}else{
				q.erase(q.begin()+x,q.end());
				q.push_back(a[j]);
			}
		}
		for(int j=0;j<q.size();j++){
			mp[q[j]]++;
//			cout<<q[j]<<' ';
		}
	} 
	for(int i=1;i<=m;i++){
		cout<<mp[i]<<' ';
	}
	return 0;
}
