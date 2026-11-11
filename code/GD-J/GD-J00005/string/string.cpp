#include<bits/stdc++.h>
using namespace std;
long long n,x,ans;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&x);
		getchar();
		scanf("%c",&c);
		for(int j=1;j<=x;j++) s+=c;
	}
	int len=s.size()-1;
	int l,r;
	if((len+1)%2==0){
		l=len/2;
		r=len/2+1;
	}
	else{
		l=len/2;
		r=len/2;
	}
	while(l>=0&&r<=len){
		if(s[l]!=s[r]) ans++;
		l--;
		r++;
	}
	printf("%lld",ans);
}

