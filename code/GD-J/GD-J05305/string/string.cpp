#include<bits/stdc++.h>
using namespace std;
const long long max1=1000000000;
long long n,k,sum=0,ans=0;
char a[max1],b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k>>b;
		for(long long j=1;j<=k;j++){
			a[sum+j]=b;
		}
		sum+=k;
	}
	for(long long i=1;i<=(sum+1)/2;i++){
		if(a[i]!=a[sum+1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
