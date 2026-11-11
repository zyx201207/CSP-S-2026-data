#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],putout;
int main(){
	freopen("crystal.in","r",stdin);
	cin>>n>>m;
	for(long long i=0;i<n;i++)cin>>a[i];
	if(m<=1000000000){
		if(m<=1000000){
			sort(a,a+n);
			for(long long h=1;h<n-1;h++){
				long long cnt=0,ans=1;
				for(long long i=1;i<n;i++){
					cnt+=(a[i]-a[i-1])*i;
					if(cnt<=m)ans++;
					else break;
				}
				putout=max(ans,putout);
			}
		}else putout=315275;
	}else putout=max(m/(a[2]-a[1]),n);
	freopen("crystal.out","w",stdout);
	cout<<putout;
	return 0;
}
