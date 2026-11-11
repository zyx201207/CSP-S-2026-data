#include<bits/stdc++.h>
using namespace std;
short a[10000005];
int n,sum,ans;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	
	for(int i=1;i<=n;i++){
		int k;
		char c;
		cin>>k>>c;
		for(int i=sum+1;i<=sum+k;i++){
			a[i]=(c-'a'+1);
		}
		sum+=k;
	}
	for(int i=1;i<=sum/2;i++){
		if(a[i]!=a[sum-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
/*
3
2 a
2 b 
1 c

*/
