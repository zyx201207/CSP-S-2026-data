#include<bits/stdc++.h>
using namespace std;
int n,m;
int c[500004];
vector<int>cnt[300004];
int ans[300004];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>c[i];
		cnt[c[i]].push_back(i);
	}
	for(int i=0;i<n;i++){
		vector<int>z(300004,0);
		int j=i;
		for(;j<n;j++){
			j=cnt[c[j]][cnt[c[j]].size()-1];
			ans[c[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}


