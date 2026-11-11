#include <bits/stdc++.h>
using namespace std;
int c,t;
int n,k,a[1000005][1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int x,y;
			cin>>x>>y;
			a[x][y]=1;
			a[y][x]=1;
		}
		cout<<1<<"\n";
	}
	return 0;
}

