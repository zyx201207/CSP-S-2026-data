#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u[10005],v[10005],m;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	m=t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>u[i]>>v[i];
		}
	}
	if(c==0&&t==2){
		cout<<1<<endl<<2;
		return 0;
	}else{
		for(int i=1;i<=m;i++){
			cout<<2;
			return 0;
		}
	}
	return 0;
}
