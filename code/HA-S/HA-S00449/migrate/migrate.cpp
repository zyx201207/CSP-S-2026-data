#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d;
long long x[2000005];
bool bj = 0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i = 1;i<=t;i++){
		bj = 0;
		cin>>n>>d;
		for(int j = 1;j<=n;j++){
			cin>>x[j];
			if(j>2&&x[j]-x[j-1]!=x[j-1]-x[j-2]){
				bj = 1;
			}
		}	
		if(bj == 0){
			if(x[2]-x[1]>=d){
				cout<<n-2<<endl;
			}else{
				if(2*(x[2]-x[1])>d){
					cout<<n-2<<endl;
				}else if(3*(x[2]-x[1])>d){
					cout<<2<<endl;
				}else{
					cout<<0<<endl;
				}
			}
		}
	}
	return 0;
}

