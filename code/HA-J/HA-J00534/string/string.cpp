#include<bits/stdc++.h>
using namespace std;
int n;
char c[200005];
int a[200005];
long long sum,ans,kp,x,y;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	ans=sum/2;
	for(int i=1,j=n; i<=n,j>=1; i++,j--) {

		x+=min(a[i],a[j]),y+=min(a[i],a[j]);

		if(c[i]==c[j]) {

			if(a[i]>a[j]) {

				a[i]-=a[j];

				a[j]=0;

				i-=1;
			} else if(a[i]<a[j]) {
				a[j]-=a[i];
				a[i]=0;
				j+=1;
			}
		} else {
			kp+=min(a[i],a[j]);
			if(a[i]>a[j]) {

				a[i]-=a[j];

				a[j]=0;

				i-=1;
			} else if(a[i]<a[j]) {
				a[j]-=a[i];
				a[i]=0;
				j+=1;
			} else {
				a[j]=0,a[i]=0;
			}
		}
		if(x==ans||y==ans)break;
	}
	cout<<kp;
	return 0;
}
