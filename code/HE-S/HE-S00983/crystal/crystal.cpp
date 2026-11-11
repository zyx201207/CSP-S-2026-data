#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],h,b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int c=a[2]-a[1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]+i;
		if(c!=a[i]-a[i-1]){
			h=1;
		}
	}
	if(h==0){
		for(int i=1;i<=n;i++){
			if(b[i]*c>m){
				cout<<i;
			}
		}
	}
	sort(a+1,a+n+1);
	long long js=0; 
	for(int i=1;i<=n;i++){
		long long d=0,jj=0;
		for(int j=i-1;j>=1;j--){
			if(d+a[i]-a[j]>m){
				break;
			}
			d+=a[i]-a[j];
			jj++;
		}
		js=max(js,jj);
	}
	cout<<js+1;
	return 0;
}
