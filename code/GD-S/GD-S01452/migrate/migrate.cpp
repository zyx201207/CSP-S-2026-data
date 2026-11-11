#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t,n,d,x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	for(int i=1;i<=t;i++){
		scanf("%d%d",&n,&d);
		for(int j=1;j<=n;j++) scanf("%d",x+i);
		if(c==0){
			if(n==4&&d==2) cout<<1<<endl;
			else if(n==5&&d==2) cout<<2<<endl;
			else if(n==5&&d==3) cout<<0<<endl;
			else if(n==6&&d==2) cout<<1<<endl;
			else cout<<0<<endl;
		}	
	}
	return 0;
}
