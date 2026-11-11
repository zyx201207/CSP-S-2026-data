#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[500005],b[50000];
int f(int h[],int maxx){
	ans=-1;
	for(int i=1;i<=m;i++){
			if(ans==-1){
				if(h[i]==1){
					ans=a[h[i]];
					continue;
				}
			}
			if(h[i]==1){
				ans&=a[h[i]];
			}	
	}
	if(ans>maxx){
		return maxx=ans;
	}
	for(int i=1;i<=m;i++){	
			h[i]=1;
			f(h,maxx);
			h[i]=0;

	}
	
}
int main()
{	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<f(b,0);
	return 0;
}

