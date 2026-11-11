#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<n;i++){
			int a,b;
			cin>>a>>b;
		}
		cout<<((n+1)/2-m)/4<<endl;
	}
	return 0;
}
