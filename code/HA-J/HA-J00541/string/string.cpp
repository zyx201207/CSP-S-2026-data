#include<bits/stdc++.h>
using namespace std;
long long n,a[210000],x,y,ans=0,r,l;
char c[210000],xx,yy;
int main(){
	freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(c[i]==c[i-1]){
			a[i]+=a[i-1];
			a[i-1]=0;
		}
	}
	x=a[1];
	y=a[n];
	xx=c[1];
	yy=c[n];
	for(int i=1;i<=n;i++){
		if(2+r+l==n){
			if(xx==yy){
				cout<<ans;
				return 0;
			}
			else{
				ans+=min(x,y);
				cout<<ans;
				return 0;
			}
		}
		if(2+r+l==n-1){
			if(x==y){
				cout<<ans+x;
				return 0;
			}
		}
		if(x>y){
			ans+=min(x,y);
			x-=y;
			r++;
			y=a[n-r];
			yy=c[n-r];
			continue;
		}
		if(x<y){
			ans+=min(x,y);
			y-=x;
			l++;
			x=a[1+l];
			xx=c[1+l];
			continue;
		}
		if(x==y){
			ans+=min(x,y);
			r++;
			y=a[n-r];
			yy=c[n-r];
			l++;
			x=a[1+l];
			xx=c[1+l];
			continue;
		}
	}
	cout<<ans;
	return 0;
}
