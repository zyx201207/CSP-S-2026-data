#include<bits/stdc++.h>
using namespace std;
long long a[500005],vis[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		vis[i]=a[i]-a[i-1];
	}
	long long l=1,r=l+1,k=m,num=1,maxx=1;
	while(r<=n){
		if(k>=vis[r]) {
			k-=vis[r];
			r++;
			num++;
		}
		else{
			maxx=max(maxx,num);
			l++;
			num--;
			k+=vis[l+1];
		}
	}
	cout<<maxx;
	return 0;
} 
