#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m;
	cin>>n>>m;
	
	vector<int> a(n+1,0),Ans(m+1,0);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	
	for(int i=1;i<=n;i++){
		vector<vector<int> > g(m+1);
		vector<int> c(m+1,0);
		for(int j=i;j<=n;j++){
			g[a[j]].push_back(j);
		}
		for(int j=i;j<=n;j++){
			int t=j,p=-1;
			for(int k=0;k<g[a[j]].size();k++){
				if(g[a[j]][k]>j){
					p=k;
					break;
				}	
			}
			if(p!=-1) j=g[a[j]][p]-1;
			else Ans[a[t]]++;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<Ans[i]<<' ';

	return 0;
}

