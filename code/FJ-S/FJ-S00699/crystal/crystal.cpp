#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e5+10;
int l,r,mid,ans;
LL n,m,gd;
LL a[N];
bool B=true;
bool check(int x){
	if(B){
		LL k=m;
		for(int j=1;j<x;j++){
			k=k-(a[x]-a[j]);
			if(k<0) return false;
		}
		return true;
	}else{
		for(int i=1;i<=n-x+1;i++){
			LL k=m;
			for(int j=i;j<i+x-1;j++){
				k=k-(a[x+i-1]-a[j]);
			}
			if(k>=0) return true;
		}	
		return false;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(i==2) gd=a[i]-a[i-1];
		else if(i!=1){
			if(a[i]-a[i-1]!=gd) B=false;
		}
 	} 
	sort(a+1,a+n+1);
	l=1,r=n;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;	
		}else r=mid-1;
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}