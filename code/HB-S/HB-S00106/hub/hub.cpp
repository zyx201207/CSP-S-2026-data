#include <bits/stdc++.h>
using namespace std;
int c,t,m,x[100000],d,n;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	int now=1,u,v;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n-1;i++){
			cin>>u>>v;
		}
		cout<<now;
		now++;
	}
	return 0;
}
