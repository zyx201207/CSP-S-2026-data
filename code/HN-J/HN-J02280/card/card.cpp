#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e6 + 100;
LL n,m,a[N],b[N],ans[N];
struct node{
	bool x;
	LL y;
}vis[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		LL k=1;
		memset(b,0,sizeof(b));
		memset(vis,0,sizeof(vis));
		
		for(int j=i;j<=n;j++){
			if(vis[a[j]].x){
				for(int s=vis[a[j]].y;s<=k;s++){
					vis[b[s]].x=0;
				}
				k=vis[a[j]].y+1;
			}else{
				vis[a[j]].x=1;
				vis[a[j]].y=k;
				b[k]=a[j];
				k++;
			}vis[a[i]].x=1,vis[a[i]].y=1;
			if(vis[b[k]].x){
				k=vis[b[k]].y+1;
			}
			//for(int t=1;t<=k;t++)cout<<b[t]<<" ";
			//cout<<endl;
		}
		//cout<<"\n";
		if(b[k]==b[k-1])k--;
		for(int s=1;s<=k;s++){
			if(b[s]!=0&&b[s]<=m)ans[b[s]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}

