//GZ-S00309 遵义航天高级中学 杨一诺 
#include<bits/stdc++.h>
using namespace std;
long long n,m,m1,h;
long long a[500005],c[500005];
long long end1;
long long max1,sum1;
long long b;
int f=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int e=a[2]-a[1];
	sort(a+1,a+n);
	for(int i=1;i<=n;i++){
		if(a[i]-a[i-1]!=e){
			f=2;
		}
		b+=a[i];
		c[i]=a[i]*i-b;
	}
	if(f==1){
		for(int i=2;i<=n;i++){
			if((a[i]*i-(a[1]+a[i])*i/2)<=m){
				max1=i;
			}
		}
		cout<<max1;
		return 0;
	}
	if(c[n]<=m){
		cout<<n;
		return 0;
	}
	for(int i=2;i<n;i++){
		sum1=0;
		m1=m;
		if(c[i]<m){
			continue;
			max1=i;
		}
		for(int j=i;j>=1;j--){
			m1-=a[i]-a[j];
			if(m1>=0){
				sum1++;
			}
			else{
				break;
			} 
		}
		if(max1<sum1){
			max1=sum1;
		}
	}
	cout<<max1;
	return 0;
}
