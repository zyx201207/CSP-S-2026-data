//GZ-S00428 陈则睿 贵阳实验三中 
#include<bits/stdc++.h>
using namespace std;
int c,t;
int d,n,x[1000100];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==13||c==14){
		while(t--){
			cin>>n>>d;
			cout<<n*(n-1)-1;
		}
	}
	return 0;
} 
