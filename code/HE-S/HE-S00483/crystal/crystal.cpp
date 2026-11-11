#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ma; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		int l=m,z=0;
		for(int j=n;j>=1;j--){
			if(a[j]>a[i])continue;
			if(l>a[i]-a[j]){
				l-=a[i]-a[j];
				z+=1;
			}
			else if(l==a[i]-a[j]){
				l-=a[i]-a[j];
				z+=1;
				break;
			}
			else{
				break;
			}
		}
		ma=max(ma,z);
	}
	cout<<ma;
	return 0;
}
