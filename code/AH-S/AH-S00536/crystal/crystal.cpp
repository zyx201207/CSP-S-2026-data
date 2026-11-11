#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	#define int long long
	int n,m,a[10000],d[10000],mi=1e9,z,y;
	cin>>n>>m;
	if(5000<=n<=500000&&1e8<=m<=1e18){
		int o=1;
		cin>>a[1]>>a[2];
		while(m>0){
			m-=o*(a[2]-a[1]);
			o++;
		}
		cout<<o;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=n-1;j++)
	{
		for(int i=1;i<=n-1;i++)
		{
			if(a[i]>a[i+1]) {
				int c=a[i];
				a[i]=a[i+1];
				a[i+1]=c;
			}
		}
	}
	for(int i=1;i<n;i++){
		d[i]=a[i+1]-a[i];
		if(mi>d[i]){
			mi=d[i];
			z=i;
			y=i+1;
		}
	}
	if(m>=d[z]){
		m-=d[z];
	}
	else {
		cout<<"1";
		return 0;
	}
	a[z]=a[y];
	while(m>0){
		if(z>1&&y<n){
			if(a[z]-a[z-1]>a[y+1]-a[y]){
				if(m>a[y+1]-a[y]){
					m=m-(a[y+1]-a[y]);
					y=y+1;
				}
				else {
					cout<<y-z+1;
					return 0;
				}
			}
			else {
				if(m>a[z]-a[z-1]){
					m=m-(a[z]-a[z-1]);
					z=z-1;
				}
				else {
					cout<<y-z+1;
					return 0;
				}
			}
		}
		if(z=1&&y<n){
			if(m>a[y+1]-a[y]){
				m=m-(a[y+1]-a[y]);
				y=y+1;
			}
			else 
			{
				cout<<y-z+1;
				return 0;
			}
		}
		if(z>1&&y==n)
		{
			if(m>a[z]-a[z-1])
			{
					m=m-(a[z]-a[z-1]);
					z=z-1;
				}
				else
				{
					cout<<y-z+1;
					return 0;
				}
		}
		if(z==1&&y==n) cout<<n;
	}
	cout<<y-z+1;
	return 0;
}
