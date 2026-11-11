#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long w,a;
	cin>>w>>a;
	while(a--){
		long long n,m,s=0;
		cin>>n>>m;
		long c[n];
		for(long long i=0;i<n;i++)cin>>c[i];
		for(long long i=0;i<n-3;i++){
			if((c[i+1]-c[i])<=m&&(c[i+2]-c[i+1])<=m&&(c[i+3]-c[i+2])<=m)s++;
		}
		cout<<s<<endl;
	}
	return 0;
}
