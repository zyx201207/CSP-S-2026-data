#include<bits/stdc++.h>
using namespace std;
long long f[200500],n,m,a[200500];
int main(){
	freopen("and3.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	f[0]=-1;
	int sss=1;
	for(int i=1;i<=30;i++){
		sss*=2;
	}f[0]+=sss;
	for(int i=1;i<=n;i++){
		int num=f[i-1]&a[1];
		int ans=a[1];
		for(int j=i;j<=n-m+i-1;j++){
			if(num<(f[i-1]&a[j])){
				ans=j;
				num=f[i-1]&a[j];
			}
		}
		f[i]=num;
		a[ans]=0;
	}
	cout<<f[n];
//	return 0;
} 
