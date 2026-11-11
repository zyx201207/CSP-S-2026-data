#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n;
	cin>>n;
	string b;
	long long b1=1;
	for(long long i=1;i<=n;i++){
		long long c;
		char c1;
		cin>>c>>c1;
		for(long long j=1;j<=c;j++){
			b[b1]=c1;
			b1++;
		}
	}
	long long l=1,r=b1-1,ans=0;
	while(l<=r){
		if(b[l]==b[r]){
			l++;
			r--;
		}else{
			ans++;
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
} 
