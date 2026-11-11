#include<bits/stdc++.h>
using namespace std;
long long n,m,maxx,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	maxx=0;
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			maxx=max(maxx,(a[i]&a[j]));
		}
	}
	cout<<maxx;
	return 0;
} 
