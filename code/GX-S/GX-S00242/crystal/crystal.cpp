#include<bits/stdc++.h>
using namespace std;
long long a[5000005];
bool cmp(int a,int b){
	return a<b;
}
long long cxy(long long aa,int m){
	long long num=0;
	if(aa>=0)for(int i=1;i<=aa;i++)num=num+a[i]-a[aa];
	return m+num;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long sum=0;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	a[n+1]=111000000;
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i+1]&&m-a[i+1]+a[i]>0){
					m=m-a[i+1]+a[i];a[i]=a[i+1];
					if(cxy(i-1,m)>0){
					for(int j=1;j<=i-1;j++)a[j]=a[i+1],m=m-a[i+1]+a[j];
					sum++;
				}
			}
		}
		cout<<sum;
	return 0;
}
