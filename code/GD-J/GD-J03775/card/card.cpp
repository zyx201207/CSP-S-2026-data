#include<bits/stdc++.h>
using namespace std;
long long c[500005],vis[300005],s[300005],id[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[c[j]]==0){
				vis[c[j]]++;
				id[c[j]]=j;
			}
			else{
				for(int h=id[c[j]];h<j;h++){
					vis[c[h]]=0;
					id[c[h]]=0;
				}
				vis[c[j]]++;
				id[c[j]]=j;
			}
		}
		for(int j=1;j<=m;j++){
			if(vis[j])s[j]++;
		}
		memset(vis,0,sizeof(vis));
		memset(id,0,sizeof(id));
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}
