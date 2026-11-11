#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=4e5+10;
int a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,p=1,q;
	ll ans=0;
	scanf("%d",&n);
	q=n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		cin>>c[i];
	}
	while(p<q){
		if(c[p]==c[q]){
			if(a[p]<=a[q]) a[q]-=a[p],p++;
			else a[p]-=a[q],q--;
		}
		else{
			if(a[p]<=a[q]) ans+=a[p],a[q]-=a[p],p++;
			else ans+=a[q],a[p]-=a[q],q--;
		}
		if(!a[p]) p++;
		if(!a[q]) q--;
	}
	printf("%lld",ans);
	return 0;
}
