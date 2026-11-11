#include <bits/stdc++.h>
using namespace std;
string s;int n;long long len,sum;
char c;
int main()
{	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		long long x;
		scanf("%lld",&x);
		cin>>c;
		len+=x;
		for(int j=1;j<=x;j++){
			s+=c;
		}
	}
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1]){
			sum++;
		}
	}
	printf("%lld",sum);
	return 0;
}

