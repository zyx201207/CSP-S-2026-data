#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans,s=0,qz[200005],cnt=1,tnc=1;
char C[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>C[i];
		s+=a[i];
		if(i!=1) qz[i]=qz[i-1]+a[i];
		else qz[i]=a[i];
	}
	for(long long i=1;i*2<=s;i++){
		cnt=1;
		tnc=1;
		while(qz[cnt]<i) cnt++;
		while(qz[tnc]<s+1-i) tnc++;
		if(C[cnt]!=C[tnc]) ans++;
	}
	printf("%lld",ans);
	return 0;
}
