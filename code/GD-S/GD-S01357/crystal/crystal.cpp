#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],c;
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1){
			for(int j=1;j<i-1;j++){
				int sum;
				if(sum+(a[i]-a[j])<=m){
					sum+=a[i]-a[j];
					b[i]++;
				}
				if(sum>=m){
					break;
				}
			}
		};
	}
	for(int i=3;i<=n;i++){
		c=max(b[i],b[i-1]);
	}
	cout<<c;
	return 0;
}
