#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200500];
int ad(long long a,long long b){
	int z=0,c=1;
	while(a>0&&b>0){
		if(a%2==1&&b%2==1){
			z+=c;
		}
		c*=2;
		a/=2;
		b/=2;
	}
	return z;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+m);
	for(int i=1;i<=n-m;i++){
		int x;
		cin>>x;
		if(x>a[1]) a[1]=x;
		sort(a+1,a+1+m);
	}
	int max1=0;
	for(int i=m;i>1;i--){
		max1=ad(a[i],a[i-1]);
	}
	cout<<max1;
	return 0;
} 
