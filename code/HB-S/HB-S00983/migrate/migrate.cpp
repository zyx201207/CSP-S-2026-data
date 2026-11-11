#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	int a[10000000008]={0};
	cin >> c >> t;
	for(int i=1;i<=t;i++){
		cin >> n >> d;
		for(int j=1;j<=n;j++){
			cin >> a[j];
		}
		for(int k=1;k<=n;k++){
			if(a[n]/2==0){
				cout << a[n]/n;
				cout << '/n';
				cout << a[n]/2+1;
			}else{
				cout << 0;
				cout << '/n';
				cout << 1;
			}
		}
	}
	
	return 0;
}
