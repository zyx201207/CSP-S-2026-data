#include<bits/stdc++.h>
using namespace std;
long long c,t,n,m;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
		}
		cout<<max(n/m/2,(n/m+n%m)/2)<<endl;
	}
	return 0;
}
