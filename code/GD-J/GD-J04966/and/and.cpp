#include<bits/stdc++.h>
using namespace std;
long long a[114514];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,sum=0;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			if(i!=j)
			sum=max(sum,a[i]&a[j]);
			//cout<<a[i]<<"&"<<a[j]<<"="<<(a[i]&a[j])<<endl;
		}
	}
	cout<<sum;
	return 0;
}
