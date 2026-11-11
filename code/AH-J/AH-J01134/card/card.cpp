#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010];
int vis[300010];
int f[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	vector<int>g(m);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int p=n;p>=1;p--){
		vector<int>v;
		for(int j=n-p+1;j<=n;j++){
			if(vis[a[j]]==1){
				int f=0;
				int w=v.size();
				for(int i=0;i<w;i++){
					if(v[i]==a[j]){
						f=1;
						v[i]=0;
						vis[a[j]]=0;
					}
					if(f==1){
						vis[v[i]]=0;
						v[i]=0;
					}
				}
			}
			vis[a[j]]=1;
			v.push_back(a[j]);
		}
		for(int k=1;k<=m;k++){
			if(vis[k]==1){
				f[k]++;
				vis[k]=0;
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<f[i]<<" ";
	return 0;
}
