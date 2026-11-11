#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
unsigned long long ct;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,n,m;
	cin>>c>>t;
	while(t--){
		scanf("%lld%lld",&n,&m);
		a[n]=0x3f3f3f3f;
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		if(c==0||c>=15&&c<=18){
			if(m<a[2]-a[1]){
				printf("0\n");
				continue;
			}
			m=m/(a[2]-a[1]);
			if(m<2){
				printf("0\n");
				continue;
			}
			printf("%lld\n",(n-(m*2ll-1ll)>0?n-(m*2ll-1ll):0));
			ct=0;
			continue;
		}
		for(int len=3;len<n;len++){
			for(int l=1;l<=n-len;l++){
				int r=l+len;
				int ret=0;
				for(int i=l+1;i<=r-1;i++){
					if(a[i]-a[l]<=m&&a[r]-a[i]<=m&&a[r]-a[l]>m) ret++;
				}
				if(ret==2) ct++;
			}
		}
		cout<<ct<<endl;
		ct=0;
	}
	return 0;
}
