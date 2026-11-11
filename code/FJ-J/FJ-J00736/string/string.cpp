#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],d=0,m=0;
char s[200005];
string c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		for(long long j=1;j<=a[i];j++)c[d++]=s[i];
	}for(int i=d-1;i>=d/2;i--)if(c[i]!=c[d-i-1])m++;
	cout<<m;
	return 0;
}
