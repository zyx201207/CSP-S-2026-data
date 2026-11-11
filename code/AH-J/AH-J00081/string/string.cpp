#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	string s;
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++){
		long long x;
		char c;
		scanf("%lld %c",&x,&c);
		s.insert(s.size(),x,c);
	}
	string ts=s;
	reverse(ts.begin(),ts.end());
	if(ts==s){
		printf("0");
		return 0;
	}
	long long l=0,r=s.size()-1,cnt=0;
	while(l<=r){
		if(s[l]!=s[r]){
			cnt++;
		}
		l++;
		r--;
	}
	printf("%lld",cnt);
	return 0;
}
