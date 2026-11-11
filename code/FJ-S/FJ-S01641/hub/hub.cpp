#include<iostream>
using namespace std;
struct Edge{
	int u,v;
}e[1000005];
int c,t,n,k,minn=99999999;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			cin>>e[i].u>>e[i].v;
		}
		cout<<minn;
		minn=99999999;
	}
	return 0;
}
