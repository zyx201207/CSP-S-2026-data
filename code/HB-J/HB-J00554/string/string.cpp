#include<bits/stdc++.h>
using namespace std;
int n;
int num;
char c;
string s = "",t = "";
long long ans = 0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d %c",&num,&c);
		for(int j = 1;j <= num;j++) s += c;
	}
	t = s;
	reverse(t.begin(),t.end());
	long long len = s.size()/2;
	for(int i = 1;i <= len;i++){
		if(t[i-1] != s[i-1]) ans++;
	}
	printf("%lld",ans);
	return 0;
}
