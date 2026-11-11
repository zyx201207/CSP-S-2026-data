#include<bits/stdc++.h>
using namespace std; 
using ll=long long;
ll n,a[200010],ans,cnt;
char c[200010];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)s+=c[i];
		cnt+=a[i];
	}
	s=' '+s;
	for(int i=1;i<=cnt/2;i++){
		if(s[i]!=s[cnt-i+1])ans++;
	}
	cout<<ans;
	return 0;
}// 3 2 a 2 b 1 c
