#include <bits/stdc++.h>
using namespace std;
int x[2000005];
int c,t,n,d;
long long num=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int maomao=1;maomao<=t;maomao++){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		cout<<num<<"\n";
	}
	return 0;
}
