#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int x[2000005];
bool f1=true;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			scanf("%d",x[i]);
			if(x[i]-x[i-1]!=x[i-1]-x[i-2]&&i>=3) f1=false;
		}
		if(f1){
			int det=x[2]-x[1];
			cout<<n/(d/det);
		}
		
	}
	
	return 0;
}
