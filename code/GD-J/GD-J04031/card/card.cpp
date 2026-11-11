#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500010],vis[200010],b[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//ЬиадA
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;i++){
		b[a[i]]=1;
	} 
	for(int i=1;i<=m;i++){
		cout<<b[i];
	}
	return 0;
}
//БљБљБљ 
