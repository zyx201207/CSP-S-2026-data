#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int x[1000000];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
    	cin>>n>>d;
    	for(int j=1;j<=n;j++){
    		cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			cout<<x[x[i]];
		}
	}
    return 0;
}

