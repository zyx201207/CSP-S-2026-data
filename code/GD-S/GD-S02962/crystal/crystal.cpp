#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5000001],b[5000001],maxj=-100000000001,c;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(maxj<=a[j]){
				maxj=a[j];
			}
		}
		for(int m=1;m<=i;m++){
			if(maxj<a[m]) continue;
			c+=(maxj-a[m]);
		}
		maxj=-100000000001;
		if(c>m) break;
		c=0;
			b[i]=i;
	}
	for(int i=1;i<=n;i++){
		if(maxj<=b[i]) maxj=b[i];
	}
	cout<<maxj;
	return 0;
}
