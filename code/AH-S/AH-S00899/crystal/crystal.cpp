#include"bits/stdc++.h"
using namespace std;
#define LL long long
const int N=5e5+5;
int n,m;

LL a[N];

int main(){
	freopen ("crystal.in","r",stdin);
	freopen ("crystal.out","w",stdout);
	scanf ("%d%d",&n,&m);

	for (int i=1;i<=n;i++){
		scanf ("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	
	bool f=1;	
	int last=a[2]-a[1];
	for (int i=3;i<=n && f;i++){
		if (last!=a[i]-a[i-1]) {
			f=0;
		}
	}
	if (!f){
		int l=a[1],r=a[n];
		LL ans=0;
		for (LL mid=l;mid<=r;mid++){
			LL k=upper_bound(a+1,a+n+1,mid)-a-1;
			LL t=m,cnt=k;
			while (t>=mid-a[cnt] && cnt>0){
				t-=mid-a[cnt];
				cnt--;
			}
			ans=max(ans,k-cnt);
	//		printf ("%lld %lld %lld\n",mid,k,cnt);
		}
		printf ("%lld\n",ans);
	}
	else{
		int cnt=n;
		while (cnt>0 && m>=a[n]-a[cnt]){
			m-=a[n]-a[cnt--];
		}
		printf ("%lld\n",n-cnt);
	}
	return 0; 
}
