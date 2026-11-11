#include<bits/stdc++.h >
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0;
	//cin>>n;
	scanf("%lld\n",&n);
	string k;
	for(int i=1;i<=n;i++){
		long long t;
		char a;
		//cin>>t>>a;
		scanf("%lld %c",&t,&a);
		for(long long j=1;j<=t;j++){
			k+=a;
		}
	}long long l=k.size();
	for(long long i=0;i<l/2;i++){
		if(k[i]!=k[l-i-1])ans++;
	}//cout<<k<<ans;
	printf("%lld",ans);
	return 0;
}
