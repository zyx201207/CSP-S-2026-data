#include<iostream>
using namespace std;
const int maxn=5e5+5;
int a[maxn],ans[maxn];
bool vis[maxn];
int n,m,pos;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)vis[j]=0;
		for(int j=i;j<=n;j++){
			if(vis[a[j]])pos=j;
			vis[a[j]]=1;
		}
		for(int j=max(pos,i);j<=n;j++){
			ans[a[j]]++;
		}
		pos=0;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
} 

