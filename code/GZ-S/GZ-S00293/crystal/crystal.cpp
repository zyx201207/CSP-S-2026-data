//GZ-S00293 遵义市第四中学 杨宜炜
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500050],d=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		long long k=m,sum=1;
		for(int j=1;j<n;j++){
			if(a[j]<=a[i]){
				k-=a[i]-a[j];
				sum++;
			}
			if(k<=0){
				break;
			}
		}
		d=max(d,sum);
	}
	cout<<d;
}
