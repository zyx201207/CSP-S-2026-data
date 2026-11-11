#include<bits/stdc++.h>
#include<algorthim>
using namespace std;
int n,m,a[505],i=1,max=0,b[505],v=0;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(;i<=n;i++){
		cin>>a[i];
	}
	for(;i<=m;i++){
		v++;
		b[i]=v;
		if(b[i]==a[i-n+1]){
			
		}
	}
	return 0;
}
