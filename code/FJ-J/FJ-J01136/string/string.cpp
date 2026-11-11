#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
long long x;
char c;
string s;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&x,&c);
		long long len=s.size();
		for(long long j=len;j<=len+x;j++){
			s[j]=c;
		}
	}
	long long len=s.size();
	for(long long i=len/2+1;i<len;i++){
		if(s[i]!=s[i-len]){
			ans++;
		}
	}
	printf("%lld",ans);
	return 0;
}
