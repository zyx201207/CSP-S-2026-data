#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[500005];
vector<int>w[300005];
vector<int>num[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int j=1;j<=n;j++){
		num[j].push_back(0);
		}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=n;j++){
		num[j].push_back(a[i-1]-a[i]);
		}
		w[a[i]].push_back(i);
	}
	for(int i=1;i<=m;i++){
		int s=w[i].size(),l=1;
		for(int j=0;j<s-1;j++){ 
			for(;l<=w[i][j];l++)num[l][l]+=m,num[l][w[i][s-1]]-=m;
			l=w[i][j]+1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
		num[i][j]=num[i][j-1]-num[i][j];
		if(num[i][j]>=1&&i<=j)
		ans[num[i][j]]++;
	}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0; 
} 

