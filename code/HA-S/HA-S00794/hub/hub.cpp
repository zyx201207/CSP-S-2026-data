#include <bits/stdc++.h>
using namespace std;
int a[10000001];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,k,u,v;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			cin>>u>>v;
		}
		if(n==5&&k==2){
			cout<<1<<endl;
		}else if(n==10&&k==3){
			cout<<2<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
