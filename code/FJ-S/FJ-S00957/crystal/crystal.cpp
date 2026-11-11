#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{	
    
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    
	long long n,m,x=1,b=0,y=0,z=1;
	cin>>n>>m; 
	b=n-1;
	y=m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	while(b>=0){
		for(int i=b-1;i>=0;i--)
		{
			if(a[i]+y>=a[b]){
				z++;
				y-=a[b]-a[i];
			}
			else break;
		}
		x=max(x,z);
		z=1;
		b--;
		y=m;
	}
	if(x==1) cout<<0;
	else cout<<x;
	return 0;
 } 
