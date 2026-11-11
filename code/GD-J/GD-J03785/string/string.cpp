#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
char s[1500000005];
int in(){
	cin>>n;
	int cnt=0;
	for(int i=1;i<=n;i++){
		int a; char b;
		cin>>a>>b;
		for(int j=1;j<=a;j++){
			s[cnt]=b;
			cnt++;
		}
	}
	return cnt;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int l=in();
	int ans=0;
	for(int i=0;i<=l/2;i++){
		if(s[i]!=s[l-i-1])ans++;
	}
	cout<<ans;
	return 0;
}
