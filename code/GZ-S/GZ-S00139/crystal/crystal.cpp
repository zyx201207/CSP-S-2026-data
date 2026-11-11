//GZ-S00139 贵阳市第一中学 张梁予 
#include<bits/stdc++.h>
using namespace std;
long long n,m,q,a[500005];

int main(){
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	q=a[2]-a[1];
	if(q==1){
		for(int i=1;i<=n;i++){
			if((1+i)*i/2>m && i*(i-1)/2<=m){
				cout<<i;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}else{
		for(int i=1;i<=n;i++){
			if((q+i*q)*i/2>m && i*(i-1)*q/2<=m){
				cout<<i;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
}
