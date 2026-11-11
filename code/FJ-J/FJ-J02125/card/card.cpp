#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	vector<int> a(n+5,0),cnt(m+2,0);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		vector<int> b;
		for(int j=i;j<=n;j++) b.push_back(a[j]);
		for(int d=1;d<=n;d++){
			for(int z=0;z<b.size();z++){
				if(b[z]==a[d]){
					while(b.size()>z) b.pop_back();
				}
			}
			b.push_back(a[d]);
		}
		for(int j=0;j<b.size();j++) cnt[b[j]]++;
		while(b.size()) b.pop_back();
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
	return 0;
}
