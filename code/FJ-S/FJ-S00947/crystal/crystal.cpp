#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=600010;
int n,m,ans,s,t,m1;
bool f=0,f1=0;
int a[MAXN];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)  scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	t=a[n/2];
	m1=m;
	for(int i=n/2;i>=1;i--){
		if(m1<=0){
			f=1;
			break;
		}
		m1-=(t-a[i]);
		s++;
	}
	if(f){
		f=1;
		int w=1;
		while(f){
			t=a[n/2-w],ans=0;
			f=0;
			m1=m;
			for(int i=n/2-w;i>=1;i--){
				if(m1<=0){
					f=1;
					break;
				}
				m1-=(t-a[i]);
				ans++;
			}
			w++;
			s=max(s,ans);
		}
	}
	if(m1>0){
		f=1;
		int w=1;
		while(f){
			t=a[n/2+w],ans=0;
			f=1;
			m1=m;
			for(int i=n/2+w;i>=1;i--){
				if(m1<=0){
					f=0;
					break;
				}
				m1-=(t-a[i]);
				ans++;
			}
			w++;
			s=max(s,ans);
		}
	}
	printf("%lld\n",s);
	return 0;
}
