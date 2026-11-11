#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10,M=3e3+10;
int n,m;
int a[N];
bool vis[M],vis1[N];
long long ans[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)vis[j]=false;
		for(int j=i;j<=n;j++){
			ans[a[j]]++;
			vis1[j]=false;
		}
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				for(int k=j-1;k>=1;k--){
					if(vis1[k])ans[a[k]]--;
					vis[a[k]]=false;
					vis1[k]=false;
					if(a[k]==a[j])break;
				}
			}
			vis[a[j]]=true;
			vis1[j]=true;
		}
		
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
