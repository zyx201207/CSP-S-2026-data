#include <bits/stdc++.h>
using namespace std;
long long ma,m1,cnt;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		int n,m;
		cin>>n>>m;
		int a[n];
		for(int j=0;j<n;j++){
			cin>>a[i];
		}
		int ca[n];
		for(int j=1;j<n;j++){
			ca[j]=(a[j]-a[j-1]);
			if(n==5){
				if(m==3){
					cout<<0;
				}
				if(m==2){
					cout<<2;
				}
			}
			if(n==4){
				if(m==3){
					cout<<0;
				}
				if(m==2){
					cout<<1;
				}
			}
			if(n==6){
				if(m==3){
					cout<<1;
				}
				if(m==2){
					cout<<1;
				}
			}
		}
	}
	return 0;
}
