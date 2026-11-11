#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define psb push_back
#define db double
const int N=5e5+5,M=3e5+5;
int n,m;
int a[N];
int ans[M];
bool vis[M];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int st[M],l=1,r=0;
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				vis[a[j]]=true;
				st[++r]=a[j];
			}
			else{
				while(l<=r){
					vis[st[r--]]=false;
					if(st[r]==a[j])break;
				}
			}
		}
		while(l<=r)ans[st[r--]]++;
		memset(vis,false,sizeof(vis));
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
return 0;}
