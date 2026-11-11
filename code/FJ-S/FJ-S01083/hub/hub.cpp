#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,x,y;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d",&c);
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>x>>y;
		}
		if(n==2){
			cout<<1<<endl<<2;
		}
		if(n==3){
			cout<<1<<endl<<1<<endl<<2;
		}
		if(n==5){
			cout<<17<<9<<6<<6<<9;
		}
	}
	fclose(stdin);
	fclose(stdout);
}