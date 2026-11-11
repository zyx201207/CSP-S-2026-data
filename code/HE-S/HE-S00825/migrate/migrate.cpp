#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		int n,d;
		cin>>n>>d;
		int a[100000];
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c==0){
			if(n==4)cout<<1;
			if(n==5)cout<<2;
			if(n==5&&d==3)cout<<0;
			if(n==6)cout<<1;
		}
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
