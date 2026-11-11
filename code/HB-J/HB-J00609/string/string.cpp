#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200005;
int n,a[N],sum=0,ans=0;
char b[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		a[i]=x;
		b[i]=y;
		sum+=x;
	}
	int i=1,j=n,l=a[1],r=a[n],ll=0,rr=0;
	while(l+r<=sum){
		if(l>=r){
			if(b[i]!=b[j]){
				ans+=r-rr;
			}
			ll+=r-rr;
			rr=r;
			j--;
			r+=a[j];
		}else{
			if(b[i]!=b[j]){
				ans+=l-ll;
			}
			rr+=l-ll;
			ll=l;
			i++;
			l+=a[i];
		}
	}
	printf("%lld",ans);
	return 0;
}
