#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
vector<int> pos[M];
int a[N],ans[M];
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		pos[i].push_back(0);
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pos[a[i]].push_back(i);
	}
	for(int i=1;i<=m;i++){
		pos[i].push_back(n+1);
	}
	ans[a[n]]=n;
	for(int i=m;i>=1;i--){
		if(i==a[n]) continue;
		for(int j=0;j<pos[i].size();j++){
			int id=pos[i][j];
			int mx=0,d=1;
			for(int k=1;k<id;k++){
				int val=a[k];
				int idx=pos[val][lower_bound(pos[val].begin(),pos[val].end(),k)-pos[val].begin()];
				if(idx>mx){
					d=k;
					mx=idx;
				}
			} 
			ans[i]+=pos[i][j]-d;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	cout<<"\n";
	return 0;
}

