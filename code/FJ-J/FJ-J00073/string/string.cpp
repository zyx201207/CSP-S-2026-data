#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
char s[10000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int num;
		char c;
		cin>>num>>c;
		for(int j=1;j<=num;j++)s[++m]=c;
	}
	for(int i=1;i<=m/2;i++){
		if(s[i]!=s[m-i+1])ans++;
	}
	cout<<ans;
	return 0;
}
