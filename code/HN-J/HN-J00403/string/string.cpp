#include<bits/stdc++.h>
using namespace std;
long long a[250081];
string s;
long long n,sum,cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		char k;
		cin>>a[i]>>k;
		sum+=a[i];
		for(long long j=1;j<=a[i];j++){
			s=s+k;
		}
	}
	for(long long i=0;i<sum/2;i++){
		long long r=sum-i-1;
		if(s[i]!=s[r]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
