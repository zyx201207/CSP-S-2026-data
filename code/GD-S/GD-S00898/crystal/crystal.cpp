#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],nm,d,mxd;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		d=1;
		nm=0;
		for(int j=i-1;j>=1;j--){
			if(nm+a[i]-a[j]>m)break;
			//cout<<a[i]-a[j]<<" ";
			nm+=a[i]-a[j];
			d++;
		}
		//cout<<endl;
		mxd=max(d,mxd);
	}
	cout<<mxd;
	return 0;
}
