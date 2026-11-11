#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int a[N];
int ans[M];
struct card{
	int num;
	int idx;	
}vis[M];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[a[j]].num!=0){
				for(int k=vis[a[j]].idx;k<j;k++){
					vis[a[k]].num--;
				}
			}
			vis[a[j]].num++;
			vis[a[j]].idx=j;
		}
		for(int j=1;j<=m;j++){
			if(vis[j].num!=0) ans[j]++;
		}
		memset(vis,0,sizeof vis);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
