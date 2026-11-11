#include <bits/stdc++.h>
using namespace std;
int a[200010],b,c,d[200010],ans,n,m,x=1;
string z[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d[i]=a[i];
		cin>>z[i];	
		b=b+a[i];
	}
	b=b/2;
	m=1;
	c=n;
	while(b>0){
		if(a[m]<=d[c]){
			if(z[m]==z[c]){
				d[c]=d[c]-a[m];
			}else{
				ans=ans+a[m];
				d[c]=d[c]-a[m];
			}
			b=b-a[m];
			m++;
		}else if(a[m]>d[c]){
			if(z[m]==z[c]){
				a[m]=a[m]-d[c];
			}else{
				ans=ans+d[c];
				a[m]=a[m]-d[c];
			}
			b=b-d[c];
			c--;
		}
	}
	cout<<ans;
	return 0;	
}
