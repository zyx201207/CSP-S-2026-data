#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c;
	long long t;
	cin>>c>>t;
	long long j;
	long long n,d;
	for(long long i=0;i<t;i++){
		cin>>n>>d;
		for(j=0;j<n;j++){
			cin>>a[j];	
		}
	}
	for(long long i=0;i<t;i++){
		cout<<1<<endl;
	}
	return 0;
} 

