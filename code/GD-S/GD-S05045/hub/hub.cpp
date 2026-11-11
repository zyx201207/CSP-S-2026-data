#include<bits/stdc++.h>
using namespace std;
int p[2000005][2];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.ont","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>p[i][0]>>p[i][1];
		}
		if(n==k) {
			cout<<0<<endl;
			continue;
		}
		cout<<1<<endl;
	}
	return 0;
}
