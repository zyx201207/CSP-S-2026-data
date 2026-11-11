#include<bits/stdc++.h>
using namespace std;
long long n,x,ans,l;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>c;
		for(int j=1;j<=x;j++){
			s=s+c;
			l++;
		} 
	}
	l-=1LL;
	long long i,j;
	if(l%2==0) i=l/2,j=l/2;
	else i=l/2,j=l/2+1;
	for(;i>=0&&j<=l;i--,j++){
		if(s[i]!=s[j]) ans++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
