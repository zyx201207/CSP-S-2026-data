#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],b[N];
bool vis[N];
deque<int>c[N];
int ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
		c[a[i]].push_back(i);
	}
	sort(b+1,b+n+1);
	bool is=true;
	for(int i=1;i<=n;i++){
		if(b[i]!=a[i]){
			is=false;
			break;
		}
	}
	if(is==true){
		for(int i=1;i<=m;i++)cout<<c[i].back()<<' ';
		return 0;
	}
	for(int x=1;x<=n;x++){
		memset(vis,0,sizeof vis);
		for(int i=x;i<=n;i++){
			for(int j=x;j<=i;j++){
				if(a[j]==a[i]&&vis[j]==0){
					for(int l=j;l<i;l++)vis[l]=1;
					break;
				}
			}
		}
		for(int i=x;i<=n;i++)if(vis[i]==0)ans[a[i]]++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
} 
