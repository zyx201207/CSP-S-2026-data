#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005],ans[1000005];
stack<int>q;
bool vis[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		ans[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		cout<<n;
	}
	return 0;
} 

