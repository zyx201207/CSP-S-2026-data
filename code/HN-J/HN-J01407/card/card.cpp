#include<bits/stdc++.h>
using namespace std;
int const N = 5e5+7;
int n,m,a[N],ans[N],q[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		map<int,int> vis;
		int tot = 0;
		for(int j=i;j<=n;j++){
			
			if(vis[a[j]]){
				for(int k=j+1;k<=tot;k++) vis[q[k]] = 0;
				tot = vis[a[j]]-1;
			}
			++tot;
			vis[a[j]] = tot;
			q[tot] = a[j];
		}
		for(int j=1;j<=tot;j++){
		//	cout<<q[j]<<' ';
			ans[q[j]]++;
		}
	//	cout<<'\n';
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}

