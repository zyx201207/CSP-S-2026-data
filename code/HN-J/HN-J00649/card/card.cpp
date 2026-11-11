#include<bits/stdc++.h>
#include<vector>
using namespace std;
//#define debug
const int N=5e5+100,M=3e5+100;
int a[N];
vector<int>v;
int n,m;
int ans[M];
int main() {
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	for(int st=1; st<=n; st++) {
		v.clear();
		for(int i=st; i<=n; i++) {
			auto idx=find(v.begin(),v.end(),a[i]);
			if(v.empty()||idx==v.end())
				v.push_back(a[i]);
			else {
				v.erase(idx,v.end());
				v.push_back(a[i]);
			}
		}
		for(int i=0; i<v.size(); i++)
			ans[v[i]]++;
	}
	for(int i=1; i<=m; i++)
		cout<<ans[i]<<' ';
}

