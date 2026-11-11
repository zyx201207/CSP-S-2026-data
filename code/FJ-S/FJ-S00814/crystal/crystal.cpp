#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long ans=0;
long long cnt;
long long c;
long long da;
long long kkk;
int n,m;
int a[N];
int b[N];
int cn[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	cnt=m;
	c=0;
	sort(a+1,a+n+1);
	int l=0;
    ans=a[1]+m;
    for(int i=1;i<n;i++)
    {
    	cn[a[i+1]-a[i]]++;
	}
	if(cn[1]==n-1){
		for(int i=1;i<=n;i++){
			da+=a[i];
			kkk++;
			if(da>m){
				printf("%lld",kkk);
				return 0;
			}
		}
	}
    for(int i=1;i<=n;i++){
    	if(ans<a[i]){
    		ans=a[i-1];
    		break;
		}
	}
	long long k=1;
	while(m--){
		a[k]++;
		if(a[k]==ans) k++;
	}
	int ma;
	for(int i=1;i<=n;i++){
	    b[a[i]]++;
	    ma=max(b[a[i]],ma);
	}
	printf("%d",ma);
	return 0;
}
