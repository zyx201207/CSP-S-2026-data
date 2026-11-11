#include <bits/stdc++.h>
using namespace std;
long long a[200010],b[200010];
char c[200010],d[200010];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ans=0,z=1,f=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		b[n-i+1]=a[i];
		d[n-i+1]=c[i];
	}
	while(z!=n+1&&f!=n+1){
		if(a[z]>b[f]){
			a[z]-=b[f];
			if(c[z]!=d[f]){
				ans+=b[f];
			}
			f++;
		}else{
			b[f]-=a[z];
			if(c[z]!=d[f]){
				ans+=a[z];
			}
			z++;
		}
	}
	cout<<ans/2;
	return 0;
}
