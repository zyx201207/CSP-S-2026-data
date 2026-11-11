#include<bits/stdc++.h>
using namespace std;
long long c,n,t,m,d;
long long a[1000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	long long s;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		s=0;
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(abs(a[k]-a[j])<d) s++;
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
