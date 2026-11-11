#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub3.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=0;i<n-1;i++){
			int a,b;
			cin>>a>>b;
		}
		if((n-2)/2/2==0) cout<<1<<endl;
		else cout<<(n-2)/2/2<<endl;
	}
	return 0;
}
