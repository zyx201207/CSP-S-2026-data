#include<bits/stdc++.h>
using namespace std;
long long n,m,s[500001],mm,t[100001],k;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&s[i]);
	}
	sort(s+1,s+n+1);
	for(long long i=1;i<=n;i++){
		t[i]=t[i-1]+s[i];
		if(s[i]<0){
			t[i]+=s[i]*2;
		}
		for(long long j=1;j<i;j++){
			k=m+(t[i]-t[j])/(i-j+1);
			if(k>=t[i]){
			    mm=max(i-j+1,mm);	
			}
		}
	}
	printf("%lld",min(m,mm));
	return 0;
} 


