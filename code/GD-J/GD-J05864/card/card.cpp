#include<bits/stdc++.h>
using namespace std;
vector<int>e[300005];
int n,m;
int a[500005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		e[a[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		int j=i;
		while(j<=n){
			ans[a[j]]++;
			j=e[a[j]][e[a[j]].size()-1]+1;
		}
		e[a[i]].erase(e[a[i]].begin());
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}

