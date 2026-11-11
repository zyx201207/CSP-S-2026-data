#include<bits/stdc++.h>
using namespace std;
long long a[500005],m,maxn=1;
long long check(long long x){
	long long cnt=1,mm=m;
	for(int i=x-1;i>=1;i--){
		if(a[x]-a[i]<=mm){
			cnt++;
			mm-=a[x]-a[i];
		}
		else
		 break;
	}
	return cnt;
}
void erfen(long long x,long long y){
	while(x<y)
	{
		long long mid=(x+y+1)/2;
		long long t=check(mid);
		if(t<maxn)
		 y=mid-1;
		else{
			maxn=t;
			x=mid;
		}
	}
	return ;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	long long n,fl=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2])
		 fl=1;
	}
	if(fl==0){
		for(int i=1;i<=n;i++){
			unsigned long long ii=a[i-1],mm=m;
			if(ii*(ii+a[1]*1ull)/2>mm){
				cout<<i-1;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	sort(a+1,a+n+1);
	erfen(1,n);
	cout<<maxn;
	return 0;
}
