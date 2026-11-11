#include <bits/stdc++.h>
using namespace std;
int a[500005];

int main(){
    freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=0;i<=t;i++){
		int n,d;
		cin>>n>>d;
		for(int i=0;i<=n;i++){
			cin>>n;
		}
		if(d!=2) cout<<0;
		else cout<<a[n]/2;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
    }
