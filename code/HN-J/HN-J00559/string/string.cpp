#include<bits/stdc++.h>
using namespace std;
const int N=2e5+6;
long long l,ans,n,a;
char c;
map<long long,char> m;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a>>c;
		for(long long j=l+1;j<=l+a;j++)m[j]=c;
		l+=a;
	}
	for(long long i=1;i<=(l>>1);i++){
		if(m[i]!=m[l+1-i])ans++;
	}
	cout<<ans;
	return 0;
} 
