#include<bits/stdc++.h>
using namespace std;
int n;
int m;
const int N=5e5+10,M=3e5+10;
int a[N];
bool vis[M];
int s[N];
int top;
int ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		top=0;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==1){
				while(s[top]!=a[j]){
					vis[s[top]]=0;
					top--;
				}
				top--;
			}
			++top;
			s[top]=a[j];
			vis[a[j]]=1;
		}
		for(int j=1;j<=top;j++){
			ans[s[j]]++;
		}
	}
	for(int i=1;i<m;i++){
		cout<<ans[i]<<" ";
	}
	cout<<ans[m];
	return 0;
}
