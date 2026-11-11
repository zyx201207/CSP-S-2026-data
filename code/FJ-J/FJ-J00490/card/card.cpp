#include<bits/stdc++.h>
using namespace std;
int n,m,s[300001];
int table[500001],p=1,ans[300001],vis[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		memset(table,0,sizeof(table));
		memset(vis,0,sizeof(vis));
		p=1;
		for(int j=i;j<=n;j++){
			if(vis[s[j]]>0){
				p=vis[s[j]];
				for(int k=p;k<j;k++){
					vis[table[k]]=0;
					table[k]=0;
				}
			}
			table[p]=s[j];
			vis[s[j]]=p;
			p++;
//			for(int k=1;k<p;k++){
//				cout<<table[k]<<" ";
//			}
//			cout<<endl;
		}
		for(int j=0;j<=p-1;j++){
			ans[table[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
		}
	return 0;
}
