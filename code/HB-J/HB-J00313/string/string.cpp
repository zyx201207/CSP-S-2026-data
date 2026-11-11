#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n;
ll a[N];
char c[N];
ll qian[N];
ll sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %s",&a[i],&c[i]);
		qian[i]=qian[i-1]+a[i];
	}
	int l=1,r=n;
	ll x=1,y=qian[n];
	while(l<r){
		ll tl=qian[l]-x+1,tr=y-qian[r-1];
		if(tl<tr){
			if(c[l]!=c[r]){
				sum+=tl;
			}
			x+=tl;
			y-=tl;
		}
		else{
			if(c[l]!=c[r]){
				sum+=tr;
			}
			x+=tr;
			y-=tr;
		}
		if(x>qian[l])l++;
		if(y<qian[r-1]+1)r--;
	}
	printf("%lld",sum);
	return 0;
}
