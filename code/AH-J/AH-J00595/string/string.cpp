#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,a;
	char c;
	string s;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%s",&a,&c);
		for(int j=1;j<=a;j++) s+=c;
	}
	ll l,r,cnt=0;
	if(n&1) l=r=(s.size()-1)/2-1;
	else{
		l=(s.size()-1)/2-1;
		r=l;
	}
	while(l>=0){
		if(s[l]!=s[r]) cnt++;
		l--;
		r++;
	}
	printf("%lld",cnt);
	return 0;
}
