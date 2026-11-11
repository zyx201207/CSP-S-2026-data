#include <bits/stdc++.h>
using namespace std;
long long n,m;
int a[100010];
char c[100010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		m+=a[i];
	}
	m/=2;
	long long cnt=0,x=0,y,ac=0,ca=0,cb=0;
	for(int i=0;i<n;i++){
		x+=a[i];
		if(x>=m){
			y=i;
			break;
		}
	}
	for(int i=n-1;i>=y;i--){
		if(c[i]!=c[ac]){
			cnt+=min(a[i]-cb,a[ac]-ca);
			if(a[i]>a[ac]){
				ac++;
				cb=a[i]-a[ac];
				i++;
			}else{
				ca=a[ac]-a[i];
			}
		}
	}
	cout<<cnt;
	return 0;
}
