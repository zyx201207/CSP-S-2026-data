#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+5,M = 3e5+5;
int a[N];
bool vis[M];
queue<int>desk;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		if(vis[a[i]]==0)desk.push(a[i]);
		else{
			desk.clear();
			desk.push(a[i]);	
		}
	}
	while(desk.size()){
		cout<<desk.top()<<" ";
		desk.pop();
	}

	return 0;
}

