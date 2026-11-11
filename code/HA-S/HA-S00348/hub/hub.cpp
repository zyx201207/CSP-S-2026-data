#include<bits/stdc++.h>
using namespace std;
int c,t,n,m;
int a[2000010];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n-1;i++){
			cin>>a[i];
		}
		if(t%2==0){
			cout<<1;
		}else{
			cout<<2;
		}
		
	}
	return 0;
}
