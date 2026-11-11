#include <bits/stdc++.h>
using namespace std;
long long n,c,cnt,s[200010],b[200010];
char a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i]>>a[i];
		s[i]=s[i-1]+b[i];
	}
	for(long long i=1;i<=n;i++){
		int j=upper_bound(s+1,s+n+1,s[n]-b[i]+1)-s;
		if(a[i]!=a[j]) cnt+=(b[i]+b[j])/2;
	}
	cout<<cnt;
	return 0;
}
