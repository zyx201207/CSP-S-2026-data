//GZ-S00407 遵义市南白中学 李徐健宇
#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,num=0,maxx=1,sum=1;
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	if(n>5000) {
		if(a[1]>a[2]) {
			int total=a[1]-a[2];
			int s=1;
			while(m>=total*s){
				sum++;
				m-=total*s;
				s++;
			}
		} else {
			int total1=a[2]-a[1];
			int s1=1;
			while(m>=total1*s1){
				sum++;
				m-=total1*s1;
				s1++;
			}
		}
		cout<<sum;
	} else {

		sort(a,a+n+1);
		for(int i=2; i<=n; i++) {
			num=0;
			int t=m;
			for(int j=1; j<=n; j++) {
				if(t>=a[i]-a[j]&&a[i]>=a[j]) {
					t-=a[i]-a[j];
					num++;
				}
			}
			if(num>maxx) maxx=num;
		}
		cout<<maxx;
	}
	return 0;
}
