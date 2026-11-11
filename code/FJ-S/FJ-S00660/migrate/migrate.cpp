#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int m,n;
	cin>>m>>n;
	while(n!=0){
		int d,g;
		cin>>d>>g;
		for(int i=1;i<=d;i++){
			cin>>a[i];
		}
		int r=(a[d]-a[1])/g;
		cout<<r;
		n--;
	}
	return 0;
} 
