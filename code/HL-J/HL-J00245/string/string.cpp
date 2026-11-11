#include<bits/stdc++.h>
using namespace std;
struct stri{
	int num;
	char cha;
}s[220000];
int n,mid,l,r,ans;
char c[1900000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int m = 1;
	for(int i = 1;i<=n;i++){
		cin>>s[i].num>>s[i].cha;
		
		for(int j = m;j<=m+s[i].num;j++){
			c[j] = s[i].cha;
		}
		
		m+=s[i].num;
	}
	l = m/2;
	ans = 0;
	for(int i = 1;i<=l;i++){
		if(c[i] != c[m-i])ans++;
	}
	cout<<ans;
	return 0;
}