#include<bits/stdc++.h>
using namespace std;
string s;
long long n,cnt,x,l,r,ans;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%s",&x,&c);
		for(int j=1;j<=x;j++){
			s[++cnt]=c;
		}
	}
	l=1;
	r=cnt;
	while(l<=r){
		if(s[l]!=s[r]){
			ans++;
		}
		r--;
		l++;
	}
	printf("%lld",ans);
	return 0;
}
