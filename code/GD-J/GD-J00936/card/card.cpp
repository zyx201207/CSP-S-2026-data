#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
ll b[300005];
ll a[500005];
ll c[500005];
ll d[300005];
bool spea=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]<a[i-1])spea=0;
		b[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(i<b[a[i]]){
			c[i]=b[a[i]];
		} 
	}
	if(n<=5000){
		memset(b,0,sizeof b);
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				b[a[j]]++;
				if(c[j]!=0)j=c[j];
			}
		}
		for(int i=1;i<=m;i++){
			printf("%d ",b[i]);
		}
	}else if(m==2){
		for(int i=1;i<=n;i++){
			b[a[i]]++;
		}
		b[a[n]]=n;
		printf("%d %d",b[1],b[2]);
	}else if(spea){
		for(int i=1;i<=m;i++){
			printf("%d",upper_bound(a+1,a+n+1,i)-n);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

