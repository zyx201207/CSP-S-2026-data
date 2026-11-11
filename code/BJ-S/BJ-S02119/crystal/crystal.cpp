#include<iostream>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int m,n,z=1;
	cin>>m>>n;
	int a[m+1];
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<m;i++){
		for(int j=i+1;j<=m;j++){
			if(a[i]>a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	for(int i=m;i>=1;i--){
		int x=n,y=1;
		for(int j=i-1;j>=1;j--){
			if(a[i]-a[j]<=x){
				y++;
				x-=a[i]-a[j];
			}
			if(x<0){
				break;
			}
		}
		if(y>z){
			z=y;
		}
	}
	cout<<z;
	return 0;
}
