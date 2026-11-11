#include<bits/stdc++.h>
using namespace std;
long long n,x[200005],cnt,len,l,r;
char c[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%c",&x[i],&c[i]);
		len+=x[i];
		for(int j=1;j<=x[i];j++) s+=c[i];
	}
	if(len%2) l=len/2,r=len/2+2;
	else l=len/2,r=len/2+1;
	while(l>=1&&r<=len){
		if(s[l-1]!=s[r-1]) cnt++;
		l--,r++;
	}
	printf("%lld",cnt);
	return 0;
}
