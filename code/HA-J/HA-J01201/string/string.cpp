#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],x,y,z,cnt,ans1,ans2,i,ys;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		x+=a[i];
	}
	ans1=1;
	ans2=n;
	i=n;
	while(z+y<x){
		for(long long j=ans1;j<=n;j++){
			z+=a[j];
			if(z==y){
				if(c[i]!=c[j]){
					cnt+=a[j];
				}
				ans1=j+1;
				i=j+1;
				break;
			}else if(y<z){
				if(c[i]!=c[j]){
					cnt+=a[i];
				}
				ans1=j+1;
				i=j;
				ys=a[j]-(z-y);
				break;
			}
			if(c[i]!=c[j]){
				cnt+=a[i];
			}
		}
		for(long long j=ans2;j>=1;j--){
			y+=a[j];
			if(y==z){
				if(c[i]!=c[j]){
					cnt+=a[j];
				}
				ans2=j-1;
				i=j-1;
				break;
			}else if(y>z){
				if(c[i]!=c[j]){
					cnt+=a[j];
				}
				ans2=j-1;
				i=j;
				ys=a[j]-(y-z);
				break;
			}
			if(c[i]!=c[j]){
				cnt+=a[j];
			}
		}
	}
	cout<<cnt/2<<endl;
	return 0;
}
