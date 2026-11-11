//GZ-J00018 金沙县第三中学  孟彧臣 
#include<bits/stdc++.h>
using namespace std;
#define long long
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n;
	cin>>n;
	long long d;
	long long a[100000000000],q[10000000000000000],sum=0;
	for(int i=0;i<n;i++){
		long long b;
		char c;
		cin>>b>>c;
		for(long long j=d;j<=b+d;j++){
			a[j]=c;
		}
		d=d+b;
	}
	for(long long i=0;i<d;i++){
		if(a[i]!=a[d-i-1]){
			a[d-i-1]=a[i];
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
