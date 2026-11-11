#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5+5;
int n;ll m,a[N],v[N],s[N],diff[N];
ll add(int l,int r){
	ll res = 0;
	for(int i=l;i<r;++i){
		res+=a[r]-a[i];
	}
	return res;
}
int main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
		if(i==1)diff[i]=0;
		else diff[i] = a[i]-a[i-1];
	}
	sort(a+1,a+1+n);
	ll od = a[2]-a[1],d;
	for(int i=3;i<=n;++i){
		d = a[i]-a[i-1];
		if(od!=d){od = -1;break;}
		od = d;
	}
	if(od!=-1){
		for(int i =2;i<=n;++i){
			v[i] = v[i-1]+(i-1)*d;
			if(v[i]>m){printf("%d",i-1);return 0;}
		}
		printf("%d",n);return 0;
	}
	int len = 1;
	ll ans=0;
	for(int i=1,j=1;j<n;j++){
		/*ans += diff[j+1]*len;
		sumd += diff[j+1];
		if(ans<=m){len++;}
		else{
			i++;
			sumd -= diff[i-1];
			ans -= sumd;
		}*/
		//printf("i%dj%d:%lld %lld\n",i,j+1,ans,sumd);
		ans = add(i,j+1);
		if(ans<=m){len++;}
		else{
			i++;
		}
	}
	printf("%d",len);
	return 0;
}
