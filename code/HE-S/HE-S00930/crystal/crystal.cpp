#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],x[500010],y[500010],s=-1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	x[1]=0;
	y[1]=0;
	for(int i=2;i<=n;i++){
		x[i]=a[i]-a[i-1];
		y[i]+=y[i-1]+x[i];
	}
	for(int i=1;i<n;i++){
		long long ans=0,k=i,l=0,ok=1;
		while(ans<m&&k<=n&&l<=n){
			if(x[k]==0&&k!=1){
			l++;
			ok++;
			} else
			{
				ans=ans+y[k]*ok-y[i]*ok;
				ok=1;
			if(ans<=m) l++;
			}
			k++;
		}
		s=max(s,l);
	} 
	cout<<s;
	return 0;
} 
