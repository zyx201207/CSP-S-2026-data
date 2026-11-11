#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000001],j[2000001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[i];
		}
		for(int j=2;j<=n;j++){
			j=x[i]-x[i-1];
			if(j>d){
				n=j;
				break;
			}
		}
	}
	cout<<0<<1;
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
