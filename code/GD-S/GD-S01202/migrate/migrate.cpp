#include<bits/stdc++.h>
using namespace std;
typedef long long lo;
lo i,j,k,l,n,m,mm,r,s,ss,a[2000005],number,t,lef[2000005],d,righ[2000005];
map<lo,lo> p;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&number,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		a[0]=-(1e18*4ll);
		a[n+1]=4ll*1e18;
		l=1,r=1;
		ss=0;
		for(i=1;i<=n;i++){
			r=max(r,i);
			while(a[i]-a[l]>d)l++;
			while(a[r]-a[i]<=d)r++;
			r--;
			lef[i]=l,righ[i]=r;
			//cout<<i<<":"<<lef[i]<<" "<<righ[i]<<"\n";
			p[lef[i]]++;
		}
		l=1;
		for(i=1;i<=n;i++){
			while(l<=n&&(lef[l]<=i||righ[l]<=righ[i]))p[lef[l]]--,l++;
			ss+=p[righ[i]-1];
		}
		printf("%lld\n",ss);
	}
	
	return 0;
}

