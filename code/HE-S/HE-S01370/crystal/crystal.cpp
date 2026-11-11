#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N];
long long b[N];
int checks(int x,int sum,int m,int s,int n){
	long long ans=0;
	for(int i=1;i<=n;++i){
		if(i==x){
			continue;
		}
		if((a[i]+b[i])<s){
			ans+=(s-(a[i]+b[i]));
			sum++;
		}
	}
	if(ans<m){
		return 0;
	}
	sum=1;
	while(m>0){
		for(int i=n;i>=1;--i){
			if(m<=0){
				break;
			}
			if((a[i]+b[i])>=s){
				continue;
			}
			b[i]++;
			m--;
		}
	}
	for(int i=1;i<=n;++i){
		if((a[i]+b[i])==s && i!=x){
			sum++;
		}
	}
	return sum;
}
//int find(int n,int m,int Max){
//	long long l=1,r=n;
//	while(l<r){
//		long long mid=(l+r)>>1;
//		if(checks(mid,0,m,a[mid],n))
//	}
//}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int Max=INT_MIN;
	for(int i=1;i<=n;++i){
		memset(b,0,sizeof(b));
		Max=max(Max,checks(i,1,m,a[i],n));
	}
	cout<<Max;
	return 0;
}
