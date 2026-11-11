#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],m,l,r,tem,ans,maxans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a,a+n);
	for(long long i=0;i<n;i++){
		if(a[i]==a[i+1]&&i!=n-1)continue;
		l=0;r=0;tem=m;ans=0;
		while(1){
			if(i-l-1!=-1){
				tem-=a[i]-a[i-l-1];
				if(tem>=0)ans++;
				else break;
				l++;
			}else{
				break;
			}
		}
		maxans=max(ans+1,maxans);
	}
	printf("%lld",maxans);
	return 0;
} 
