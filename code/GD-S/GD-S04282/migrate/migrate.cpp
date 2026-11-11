#include<bits/stdc++.h>
using namespace std;
int n,d,v,g;
long long x[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(i-1>0){
				if(i==2){
					g=x[2]-x[1];
				}
				else if(g!=x[i]-x[i-1]){
					d=1;
				}
			}
		}
		if(!d){
			if(d<g*2){
				cout<<0;
				continue;
			}
			else if(n>=3){
				cout<<1;
				continue;
			}
			
		}
		cout<<1;
	}
	return 0;
}
