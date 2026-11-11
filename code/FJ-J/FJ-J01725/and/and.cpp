#include<bits/stdc++.h>
using namespace std;
int n,m,a[300100];
int y(int a,int b)
{
	int ya[21],yb[21],la=0,lb=0;
	int j=1;
	while(a>0){
		ya[j]=a%2;
		a/=2;
		j++;
		la++;
	}
	j=1;
	while(b>0){
		yb[j]=b%2;
		b/=2;
		j++;
		lb++;
	}
	j=1;
	int ans=0;
	int minn=min(la,lb);
	for(int i=1;i<=minn;i++){
		if(ya[i]==1&&yb[i]==1)ans+=j;
		j*=2;
	}
	return ans;
}
int main()
{
	freopen("and.in","w",stdin);
	freopen("and.out","r",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int maxx=0;
	if(m==1){
		for(int i=1;i<=n;i++)
		{
			maxx=max(maxx,y(a[i],0));
		}
		cout<<maxx;
		return 0;
	}
	if(m==n){
		maxx=y(a[1],a[2]);
		for(int i=3;i<=n;i++)
			maxx=y(maxx,a[i]);
		cout<<maxx;
		return 0;	
	}
	if(m==n-1){
		int minn=0;
		maxx=y(a[1],a[2]);
		for(int i=3;i<=n;i++)
			maxx=y(maxx,a[i]);
		for(int i=1;i<=n;i++)
			minn=max(minn,y(maxx,a[i]));
		cout<<minn;
		return 0;
		}
	
	return 0;
 } 
