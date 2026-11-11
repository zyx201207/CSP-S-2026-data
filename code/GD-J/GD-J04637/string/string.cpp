#include<bits/stdc++.h> 
using namespace std;
const int N=300000;
long long a[N],ans,b[N],n,m,l;
char p;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&l);
		cin>>p;
		m+=l;
		for(long long j=1;j<=l;j++) s+=p;
	}
	if(m%2){
	    for(long long i=0;i<m/2;i++)
	    	if(s[i]!=s[s.size()-i-1]) ans++;
	}
	else{
		if(s[m/2]!=s[m/2-1]) ans++;
		for(long long i=0;i<m/2-1;i++)
	    	if(s[i]!=s[s.size()-i-1]) ans++;
	}
	printf("%lld",ans);
	return 0;
}
