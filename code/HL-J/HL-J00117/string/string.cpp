#include <bits/stdc++.h>
using namespace std;
long long n,t,sum,ans;
char a[9000000];
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t>>c;
		for(int j=1;j<=t;j++){
			sum++;
			a[sum]=c;
		}
	}
	for(long long i=1;i<=sum/2;i++){
		if(a[i]!=a[sum-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
