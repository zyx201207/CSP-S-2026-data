#include<bits/stdc++.h>
using namespace std;
long long a,b,cnt=0;
string c,n,s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>b>>c;
		for(int j=1;j<=b;j++) n=n+c;
	}
	s=reserve(n)
	for(long long j=1;j<=n.size()/2+1;j++){
		if(s[j]!=n[j]) cnt++;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
