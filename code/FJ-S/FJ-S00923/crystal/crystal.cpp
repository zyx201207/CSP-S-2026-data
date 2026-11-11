#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N]={},b[N]={};
bool cmp(long long a,long long b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)b[i]=a[n]-a[i];
	//for(int i=1;i<=n;i++)cout<<b[i]<<' ';
	long long k=0;
	long long s=0,ans=0;
	long long l=n,r=n;
	while(r>=1){
		k+=b[r]-b[l];
		r--;
		s++;
		while(k>=m){
			k-=(l-r)*(b[l-1]-b[l]);
			l--;
			s--;
		}
		ans=max(s,ans);
	}
	cout<<ans;
	return 0;
}
