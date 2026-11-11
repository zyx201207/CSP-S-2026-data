#include<bits/stdc++.h>
#define N 500010
#define LL long long
using namespace std;
LL n,m,a[N],b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	LL l=0,r=n+1;
	while(l+1<r){
		LL mid=(l+r)/2,f=0;
		for(int i=1;i+mid-1<=n;i++){
			LL x=i,y=i+mid-1;
			if(a[y]*mid-(b[y]-b[x-1])<=m){
				f=1;
				break;
			}
		}
		if(f==1){
			l=mid;
		}else{
			r=mid;
		}
	}
	cout<<l;
	return 0;
}
