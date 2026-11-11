#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const long long MINN=-(1e12+5);
const long long MAXN=1e12+5;
long long a[N];
long long ans=1;
long long n,m;
long long mx=MINN;
long long mn=MAXN;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		mn=min(a[i],mn);
	}
	sort(a+1,a+n+1);
	for(long long i=mn;i<=mx;i++){
		long long cnt=0;
		long long sum=m;
		for(int j=1;j<=n;j++){
			if(a[j]<=i){
				if(sum-(i-a[j])>=0){
					cnt++;
					sum-=i-a[j];
				}
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
