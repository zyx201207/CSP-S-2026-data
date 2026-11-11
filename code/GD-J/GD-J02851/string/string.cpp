#include<bits/stdc++.h>
using namespace std;
string a,b;
long long n,ans=0,now=0,bnow=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		long long t;
		char t1;
		scanf("%lld %c",&t,&t1);
		for(long long j=0;j<t;j++){
			a[now]=t1;
			now++;
		}
	}
	bnow=now-1;
	for(long long i=0;i<now;i++){
		b[bnow]=a[i];
		bnow--;
	}
	for(long long i=0;i<now/2;i++){
		if(b[i]!=a[i])ans++;
	}
	cout<<ans;
	return 0;
}
