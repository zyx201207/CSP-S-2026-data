#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
long long a[N+5],ma,j,n,m;
void f(){
	int i=1;
	while(m>0){
		m-=i;
		i++;
	}
	cout<<i-1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n>5000){f();return 0;}
	if(n*(a[n]-a[1])>98000000){cout<<n/2;return 0;}
	for(int i=a[1];i<=a[n];i++){
		long long d=0;
		for(j=1;j<=n;j++){
			d+=i-a[j];
			if(d>m)break;
			if(i-a[j]<0){j--;break;}
			if(j==n)break;
		}
		ma=max(ma,j);
	}
	cout<<ma;
	return 0;
} 
