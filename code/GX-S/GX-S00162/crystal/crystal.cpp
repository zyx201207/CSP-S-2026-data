#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n];
	long long b[n-1];
	//long c[n-1];
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a+0,a+n-1);
	long long d=0,e=0,k=2,h=0,t=0;
	for(int i=n-1;i>0;i--){
		b[d]=a[i]-a[i-1];
		//cout<<b[d]<<' ';
		d++;
		}
		//cout<<endl;

	long long y=0;
	h=b[0];
	
	for(int i=0;i<n-1;i++){
		//cout<<y<<i<<k<<endl;
		
		e=b[i]+e+e;
			k=i-y+2;
			while(e>m){
			
			if(t<k)t=k;

			
			
			y++;
			if(y<n-1)
			e-=h*(k-1);
			h=b[y];
			//cout<<'g';
			//cout<<e;
			}
			
			}
		
		if(t<k)t=k;
	
	cout<<t;
	
	
return 0;
}
