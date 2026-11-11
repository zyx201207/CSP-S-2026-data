#include<bits/stdc++.h>
using namespace std;
string s;
long long n,m,ans=0;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long k=0;
	for(long long i=1;i<=n;i++){
		cin>>m>>c;
		for(long long j=1;j<=m;j++){
			s[k++]=c;
		}
	}
	long long zd;
	zd=k/2;
	for(long long i=1;i<=zd;i++){
		if(s[zd-i]!=s[zd+i]){
			ans++;
			s[zd+i]=s[zd-i];
		}
	}
	cout<<ans;
		return 0;
} 
