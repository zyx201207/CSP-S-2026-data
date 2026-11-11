#include<bits/stdc++.h>
using namespace std;
long long n,x=0,t,c=0;
char y;
string s[200015];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>t>>y;
		for(long long j=1;j<=t;j++){
			s[x++]=y;
		}
	}
		for(long long i=0;i<=x/2;i++){
			if(s[i]!=s[x-i-1]) c++;
		}
	cout<<c;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

