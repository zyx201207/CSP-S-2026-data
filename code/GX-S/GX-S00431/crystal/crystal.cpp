#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",in);
	freopen("crystal.out","w",out);
	int n,mj,a[101]={0},c[101]={0},d=0;
	cin>>n>>mj;
	int b[mj+1]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int y=1;y<=mj;y++){
				a[y]+=a[j];
				if(a[y]==a[3]){
					b[j++];
				}
				for(int k=1;k<=n;k++) a[k]=c[k];
			}
			for(int k=1;k<=n;k++) a[k]=c[k];
		}
	}
	d=b[1];
	for(int i=1;i<=mj;i++){
		for(int j=1;j<=mj;j++){
			if(b[i]<b[j]){
				d=b[j];
			}
		}
	}
	cout<<d;
	return 0;
}
