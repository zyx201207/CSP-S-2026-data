#include<bits/stdc++.h>
int n;
long long m;
long long a[500005];
long long b[500005];
int ans=1;
void ask(int l,int r){
	int need=b[r]-b[l]-(a[r]-a[l])*(l-1);
	if(need<=m){
		ans=std::max(ans,r-l+1);
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	std::sort(a+1,a+n+1);
	int i,j;
	i=j=1;
	long long x=0;
	while(j<n){
		j++;
		if(x+(a[j]-a[j-1])*(j-i)<=m){
			x+=(a[j]-a[j-1])*(j-i);
			ans=std::max(ans,j-i+1);
		}else{
			j--;
			if(i==j){
				i++;
				j++;
			}else{
				x-=a[j]-a[i];
				i++;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
