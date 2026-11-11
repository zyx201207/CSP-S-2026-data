#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005;

long long n,m;
long long N[maxn],dot[maxn],qzh[maxn];
long long ad=0;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> N[i]; 
		
		if(N[i]<ad)ad=N[i];
	}
	
	ad=abs(ad);
	for(int i=1;i<=n;i++){
		if(ad)N[i]+=ad;
	}
	
	sort(N+1,N+1+n);
	
	for(long long i=2;i<=n;i++){
		qzh[i]=qzh[i-1]+N[i];
		dot[i]=i*N[i] - qzh[i];
	}
	
	long long l=0,r=1;
	long long ans=0;
	
	while(r <= n){
		long long ned=dot[r]+qzh[l]-N[r]*l;
		if(ned <= m){
			ans=max(r-l,ans);
			r++;
		}
		if(ned > m){
			l++;
		}
	}
	cout << ans;
	
	return 0;
} 
