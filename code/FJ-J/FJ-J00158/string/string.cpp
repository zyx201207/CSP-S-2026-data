#include<bits/stdc++.h>
using namespace std;
int n;
char s[1000000005];
long long a[200005],cnt=-1,ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)s[++cnt]=c[i];
	}
	for(int i=0;i<=cnt/2;i++)
		if(s[i]!=s[cnt-i])ans++;
	cout<<ans;
	return 0;
} 
