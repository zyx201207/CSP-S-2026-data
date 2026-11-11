#include<bits/stdc++.h>
using namespace std;
int b[100086];
int a[100086];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	cin>>c>>t;
	for(int i = 1;i<=t;i++){
		cin>>n>>d;
		for(int j = 0;j<=n;n++){
			cin>>b[j];
		}
		if(c = 0){
			a[i] = i;
		}	
	}
	return 0;
}
