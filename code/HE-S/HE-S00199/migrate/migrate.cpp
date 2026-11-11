#include<bits/stdc++.h>
using namespace std;
int c,t;
int a[100000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int x=a[2]-a[1];
		if(x>=d) {
			cout<<0;
		}
	}
	return 0;
}

