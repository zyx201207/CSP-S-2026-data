#include<bits/stdc++.h>
using namespace std;
long long n;
string ans;
long long cnt = 0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long a;
	char c;
	for(long long i=1;i<=n;i++){
		cin>>a>>c;
		for(long long j=1;j<=a;j++){
			ans+=c;
		}
	}
	long long len = ans.length();
	for(long long i=0;i<len/2;i++){
		if(ans[i]!=ans[len-i-1])cnt++;
	}
	cout<<cnt;
	return 0;
}
