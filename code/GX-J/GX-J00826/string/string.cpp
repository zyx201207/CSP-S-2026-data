#include<bits/stdc++.h>
using namespace std;
long long n,x,l,ans;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&x);
		scanf("%s",&c);
		for(int j=1;j<=x;j++){
			s+=c;
			l++;
		}
	}
	long long mid=l/2;
	for(int i=0;i<=mid;i++){
		if(s[mid-i+mid]!=s[i]) ans++;
	}
	cout<<ans;
	return 0;
}
