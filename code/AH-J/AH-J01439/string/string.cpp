#include<bits/stdc++.h>
using namespace std;
long long n,ans,l=1;
char s[0x3f3f3f3f];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long k;
		char c;
		cin>>k>>c;
		for(long long j=1;j<=k;j++){
			s[l]=c;
			l++;
		}
	}
	l--;
	long long j=l;
	for(long long i=1;i<=l/2;i++){
		if(s[i]!=s[j]){
			ans++;
		}
		j--;
	}
	cout<<ans;
	return 0;
}
