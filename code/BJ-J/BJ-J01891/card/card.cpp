#include<bits/stdc++.h>
using namespace std;
int a[5005],ans[5005];
vector<int> v[2];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		for(int i=k+1;i<=n;i++){
			for(int j=0;j<(int)v[(i-1)%2].size();j++){
				if(a[i]==v[(i-1)%2][j])break;
				v[i%2][j]=v[(i-1)%2][j];
			}
			v[(i-1)%2].clear();
			v[i%2].push_back(a[i]);
		}
		for(int j=0;j<(int)v[n].size();j++){
			ans[v[n][j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
}
