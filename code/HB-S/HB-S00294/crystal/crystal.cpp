#include<bits/stdc++.h>
using namespace std;
long long n,m,m1,a[500005],b,max1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			b=m1;
			if(m1-(a[i]-a[j])>=0){
				m1=m1-(a[i]-a[j]);
			}else{
				b=i-j-1;
				max1=max(max1,b);
				break;
			}
		}
	}
	cout<<max1;
	return 0;
}
