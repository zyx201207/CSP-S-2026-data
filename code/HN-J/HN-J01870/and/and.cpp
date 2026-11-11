#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(m==1){sort(a+1,a+1+n);cout<<a[n];return 0;}
	if(m==n){int ans=a[1];for(int i=2;i<=n;i++)ans=ans&a[i];cout<<ans;return 0;}
	if(m==2){int ans=0;for(int i=1;i<n;i++)for(int j=i+1;j<=n;j++)ans=max(ans,(a[i]&a[j]));cout<<ans;return 0;}
	sort(a+1,a+1+n);
	if(m==n-1){cout<<a[2];return 0;}
	if(a[n]<4){int c[4]={0};for(int i=1;i<=n;i++)c[a[i]]++;if(c[3]>=m){cout<<3;return 0;}if((c[2]+c[3])>=m){cout<<2;return 0;}if((c[1]+c[3])>=m){cout<<1;return 0;}cout<<0;return 0;}
	if(a[1]==1){cout<<a[n-m+1];return 0;}
	int ans=a[n];
	for(int i=0;i<m;i++)ans=ans&a[n-i];
	cout<<ans;
	return 0;
}

