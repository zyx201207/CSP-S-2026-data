#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[200005];
char ch;
char s[1000000005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ch;
		while(a[i]--)
			s[++m]=ch;
	}
	for(int i=1;i<=m/2;i++)
		if(s[i]!=s[m-i+1])
			ans++;
	cout<<ans;
	return 0;
}
