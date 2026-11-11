#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int a[N],b[M],vis[M],ans[M],id[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof vis);
		for(int j=n;j>=i;j--){
			if(vis[a[j]]+1>=2){
				
				ans[a[j]]++;
				vis[a[j]]=1;
				for(int k=j;k<id[a[j]];k++){
					ans[a[k]]--;
				}
				id[a[j]]=j;	
			}else{
				vis[a[j]]++;
				id[a[j]]=j;
				ans[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

