#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[10000001];
	for(int i=0;i<=n;i++){
		cin>>a[i];
	}
	long long sum=abs(a[1]+a[2]);
	cout<<sum<<endl;
	return 0;
}
