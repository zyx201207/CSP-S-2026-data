#include<bits/stdc++.h>
using namespace std;
int n,m,ans[500005],a[500005],vis[500005];
vector<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			while(q.back()==a[i]&&vis[a[i]]==1){
				q.pop_back();
			}
			q.pop_back();
			q.push_back(a[i]);
			vis[a[i]]=1;
		}
		for(int j=0;j<q.size();j++)
			ans[q[i]]++;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
}
