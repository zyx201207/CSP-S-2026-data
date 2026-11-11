#include<bits/stdc++.h>
using namespace std;
int n;
long long ii,r;
string s;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	if (n==1){
		cout<<0;
		return 0;
	}
	for (int i=1;i<=n;i++){
		long long a;
		char c;
		scanf("%lld",&a);
		r+=a;
		cin>>c;
		for (long long j=ii;j<a+ii;j++){
			s[j]=c;
		}
		ii+=a;
	}
	r=r-1;
	long long l=0;
	for (long long i=0;i<r/2+1;i++){
		if (s[l]==s[r]) continue;
		else ans++;
		l++;
		r--;
	}
	cout<<ans;
}
