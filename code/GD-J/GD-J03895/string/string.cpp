#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	char a[100005];
	long long u=0;
	for(int i=1;i<=n;i++){
		long long z;
		cin>>z;
		char q;
		cin>>q;
		for(long long j=1;j<=z;j++){
			u++;
			a[u]=q;
		}
	}
	long long ans=0;
		for(int i=1;i<=u/2;i++){
		if(a[i]!=a[u-i+1]){
			ans++;
		}
}
	cout<<ans;
	return 0;
}
