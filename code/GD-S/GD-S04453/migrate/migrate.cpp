#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate4.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	for(long long i=0;i<t;i++){
		long long n,d,a[114514];
		cin>>n>>d;
		for(long long j=0;j<n;j++){
			cin>>a[j];
		}
		cout<<n-2*d+1<<endl;
	} 
}
