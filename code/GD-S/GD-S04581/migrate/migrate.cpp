#include<bits/stdc++.h>
using namespace std; 
long long N,n,m,a[114514],ans,s,e;
struct aa{
	long long sum,ml;
};
aa lx(long long x,long long d){
	if(x==e){
		aa t;
		t.ml=d;
		t.sum=1;
		return t;
	}
	long long sum=0,ml=-1;
	for(int i=e;i>=x+1;i--){
		if(a[i]-a[x]<=m){
			aa t=lx(i,d+1);
			if(ml==-1){
				ml=t.ml;
				sum=t.sum;
			}
			else{
				if(ml==t.ml){
					sum+=t.sum;
				}
				if(sum>2){
					break;
				}
			}
		}
	}
	aa tt;
	tt.ml=ml;
	tt.sum=sum;
	return tt;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld %lld",&N,&N);
	for(int I=0;I<N;I++){
		ans=0;
		memset(a,0,sizeof(a));
		scanf("%lld %lld",&n,&m);
		for(int i=0;i<n;i++){
			scanf("%lld",&a[i]);
		}
		sort(a,a+n);
		for(int i=0;i<n-2;i++){
			for(int j=i+2;j<n;j++){
				s=i;
				e=j;
				aa t=lx(s,0);
				ans+=(t.sum==2);
			}
		}
		printf("%lld\n",ans);
	}
}
