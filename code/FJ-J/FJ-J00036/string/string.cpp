#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10;
long long l,n,a[MAXN],mid,ans;
char ch[MAXN];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ch[i];
		l+=a[i];
		for(int j=1;j<=a[i];j++)s+=ch[i];
	}
	mid=l/2;
	for(long long x=0,r=l-1;x<mid;x++,r--)if(s[x]!=s[r])ans++;
	printf("%lld",ans);
	return 0;
}
