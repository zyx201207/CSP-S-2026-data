#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a[9999];
	int n;
	int m;
	cin>>m;
	cin>>n;
	int ans[9999];
	for(int i=0;i<n;i++){
		cin>>a[i];
		
	}
	int k[1000]=0;
	
	for(int j=0;j<n;j++){
		for(int i2=0;i2<m;i2++){
			k[i2]+=a[j] & a[i2+j+1];
		}
			ans[j+i2]=k;
		
		
	}
	int la=0;
	for(int h=0;h<n-1;h++){
		la=max(ans[h],ans[h+1]);
	}
	cout<<la;
	
	
	return 0;
}
