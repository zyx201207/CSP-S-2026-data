#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b,x=0,maxx=0,type=1,ty;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	b=m;
	cin>>a[1]>>a[2];
	ty=a[2]-a[1];
	for(int i=3;i<=n;i++){
		cin>>a[i];
		if(a[i]-a[i-1]!=ty) type=0;
	}
	if(type==1){
		int tf=0;
		for(int i=2;i<=n;i++){
			if((i*(i-1)*ty/2)>m){
				maxx=i-1;
				tf=1;
				break;
			}
		}
		if(tf==0) maxx=n;
	}
	else{
		for(int i=2;i<=n;i++){
			x++;
			while(x>0){
				if((a[i]-a[i-1])*x<=b){
					b-=(a[i]-a[i-1])*x;
					maxx=max(maxx,x+1);
					break;
				}
				else{
					b+=(a[i-1]-a[i-x]);
					x--;				
				}
			}
		}
	}
	cout<<maxx;
	
	return 0;	
} 
