#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
long long a[200100],p[200100];
char c[200100],q[200100];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		p[n-i+1]=a[i];
		q[n-i+1]=c[i];
	}
	for(int i=1,j=1;i<=n&&j<=n;){
		if(a[i]<p[j]){
			if(c[i]!=q[j]){
				ans+=a[i];
			}
			p[j]-=a[i];
			i++;
		} else {
			if(c[i]!=q[j]){
				ans+=p[j];
			}
			a[i]-=p[j];
			j++;
		}
	}
	ans/=2;
	cout<<ans;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/
