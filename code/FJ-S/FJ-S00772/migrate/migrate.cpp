#include <bits/stdc++.h>
using namespace std;

const int N=2e6+10;
int c,t;
int n,d;
int a[N];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int o=n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n<4){
			cout<<"0\n";
			continue;
		}
		if(n==4){
			if(a[2]-a[1]>d || a[3]-a[1]>d){
				cout<<"0\n";
			}else{
				cout<<"1\n";
			}
			continue;
		}
	}
	return 0;
}
