#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,x=1,ans,maxx;
ll a[500010],b[500010],c[500010],d[500010],sumb[500010],summ1[500010];
bool fl1=0,fl2=0;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(nullptr);
	/*
	while((double)clock()/CLOCKS_PER_SEC<0.9){

	}
	uniform_int_distribution<int> dist(1,100);
	*/
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]!=i) {
			fl1=1;
		}
		if(i>=3) {
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]) {
				fl2=1;
			}
		}
	}
	sort(a+1,a+1+n);
	b[1]=1;
	d[1]=a[1];
	for(int i=2; i<=n; i++) {
		while(i<=n && a[i]==a[i-1]) {
			b[x]++;
			i++;
		}
		maxx=max(maxx,b[x]);
		b[++x]=1;
		c[x]=a[i]-a[i-1];
		d[x]=a[i];
	}
	ans=maxx;
//	cout<<x;
	sumb[1]=b[1];
	for(int i=2; i<=x; i++) {
		sumb[i]=sumb[i-1]+b[i];
		summ1[i]=summ1[i-1]+b[i]*c[i];
//		cout<<c[i]<<" "<<sumb[i]<<" "<<summ1[i]<<" "<<d[i]<<'\n';
	}
	if(n<=5000) {
		for(int i=2; i<=x; i++) {
			ll sss=0;
			for(int j=i-1; j>=1; j--) {
				sss+=b[j]*(d[i]-d[j]);
				if(sss<=m) {
					if(j!=1) {
						if((m-sss)/(d[i]-d[j-1])>=b[j-1]) {
							continue;
						}
						ans=max(ans,(sumb[i]-sumb[j-1])+(m-sss)/(d[i]-d[j-1]));
					} else {
						ans=max(ans,sumb[i]-sumb[j-1]);
					}
				} else {
					break;
				}
//			if(summ1[i]-summ1[j]<=m) {
//				if(j!=1) {
//					ans=max(ans,(sumb[i]-sumb[j])*(d[i]-d[j])+(m-sumb[i]+sumb[j])/(d[i]-d[j-1]));
//				} else {
//					ans=max(ans,(sumb[i]-sumb[j])*(d[i]-d[j]));
//				}
//			}else{
//				break;
//			}
//			cout<<i<<" "<<j<<" "<<sumb[i]-sumb[j-1]<<" "<<d[i]-d[j]<<" "<<sss<<" "<<d[i]-d[j-1]<<" "<<ans<<'\n';
			}
		}
	} else {
		if(fl1==0) {
			for(int i=1; i<=n; i++) {
				if(i*(i-1)/2>m) {
					cout<<i-1<<'\n';
					return 0;
				}
			}
		}
		if(fl2==0) {
			for(int i=1; i<=n; i++) {
				if((i)*(a[2]-a[1])*(i-1)/2>m) {
					cout<<i-1<<'\n';
					return 0;
				}
			}
		}
		for(int i=2; i<=x; i++) {
			ll sss=0,l=1,r=i-1,mid;
			while(l<r) {
				mid=(l+r)/2;
				sss=summ1[i]-summ1[mid]+(sumb[i]-sumb[mid])*(d[mid]-d[1]);
				if(sss<=m) {
					if(mid!=1) {
						if((m-sss)/(d[i]-d[mid-1])>=b[mid-1]) {
							r=mid;
							ans=max(ans,(sumb[i]-sumb[mid-1])+b[mid-1]);
							continue;
						}
						ans=max(ans,(sumb[i]-sumb[mid-1])+(m-sss)/(d[mid-1]));
					} else {
						ans=max(ans,sumb[i]-sumb[mid-1]);
					}
					r=mid;
				} else {
					l=mid+1;
				}
//			if(summ1[i]-summ1[j]<=m) {
//				if(j!=1) {
//					ans=max(ans,(sumb[i]-sumb[j])*(d[i]-d[j])+(m-sumb[i]+sumb[j])/(d[i]-d[j-1]));
//				} else {
//					ans=max(ans,(sumb[i]-sumb[j])*(d[i]-d[j]));
//				}
//			}else{
//				break;
//			}
//			cout<<i<<" "<<mid<<" "<<sumb[i]-sumb[mid-1]<<" "<<d[i]-d[mid]<<" "<<d[mid]<<" "<<sss<<" "<<d[i]-d[mid-1]<<" "<<ans<<'\n';
			}
		}
		cout<<ans<<'\n';
		return 0;
	}
	cout<<ans<<'\n';
	return 0;
}
