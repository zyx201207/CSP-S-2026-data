#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
using ll=long long;
ll a[500005];
ll cha[500005];
ll p[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	int f=1;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
		if(i>=3){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2])f=0;
		}
	}
	sort(a+1,a+1+n);
	ll s=0,cnt=0;
	for(ll i=2;i<=n;++i){
		cha[i]=a[i]-a[i-1];
	}
	ll ans=0;
	p[0]=0;	
	if(f){
		for(ll i=1;i<=n;++i){
			s+=cha[i];
			cnt+=s;
			if(cnt<=m){
				++ans;
			}
			else break;
		}
		printf("%lld",ans);		
	}else{
		for(ll i=1;i<=n;++i){
//			s+=cha[i];
			p[i]=p[i-1]+cha[i]*(i-1);
		}
		cnt=0;
		for(ll l=1,r=1;r<=n;){
			while(l>r)++r;
			if(cnt<=m){
				if((cnt+cha[r+1]*(r+1-l))>m){
					ll o=r-l+1,k=r+1;
					while(a[k]==a[r]){
						++k;
						++o;
					}
					ans=max(ans,o);
					if(l<=r)cnt-=a[r]-a[l];
					++l;
				}else{
					++r;
					cnt+=cha[r]*(r-l);
				}
			}else{
				if(l<=r)cnt-=a[r]-a[l];
				++l;
			}
		}
		printf("%lld",ans);
	}

	return 0;
}
