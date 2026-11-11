#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],d[500005];
long long ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		d[i]=a[i+1]-a[i];
	}
	long long s1=0,s2=0,l=0;
	for(int r=1;r<n;r++){
		s2+=d[r];
		s1+=d[r]*(r-l);
		while(s1>m){
			l++;
			s1-=s2;
			s2-=d[l];
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
