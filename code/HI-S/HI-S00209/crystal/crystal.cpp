#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000001],ma;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	long long k=n,l=n,yong;
	while(l>1){
		if(yong+a[k]-a[l-1]<=m){
			l--;
			yong=yong+a[k]-a[l];
		}else{
			if(l>=k){
				l=k-1;
			}else{
				yong=yong-(a[k]-a[k-1])*(k-l);
			}
			k--;
		}
		ma=max(ma,k-l+1);
	}
	cout<<ma;
	
	return 0;
}
