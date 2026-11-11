#include<bits/stdc++.h>
using namespace std;
int n,m; 
int x,y,z=1;
int a[200010];
int bb,cc;
int suma,zh,zhc=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		x=a[i];
		y=0;
		z=1;
		for(int j=0;;j++){
			if(x==1){
				y+=z;
				break;
			}
			y+=(x%2)*z;
			z*=10;
			x/=2;
		}
		a[i]=y;
	}
	for(int i=0;i<n;i++){
		zhc=1;
		zh=0;
		zhc=1;
		zhc=1;
		bb=a[i];
		cc=a[i+1];
		for(int k=0;;k++){
			if(cc==0 || bb==0){
				break;
			}
			if(bb%10==cc%10){
				zh+=(bb%10)*zhc;
			}
			zhc*=10;
			bb/=10;
			cc/=10;
		}
		for(int j=2;j<m;j++){
			zhc=1;
			bb=zh;
			cc=a[i+j];
			for(int k=0;;k++){
				if(cc==0 || bb==0){
					break;
				}
				if(bb%10==cc%10){
					zh+=(bb%10)*zhc;
				}
				zhc*=10;
				bb/=10;
				cc/=10;
			}
				
		}
	bb=zh;
	zh=0;
	zhc=1;
	for(int k=0;;k++){
		if(bb==0){
			break;
		}
		zh+=(bb%10)*zhc;
		zhc*=2;
		bb/=10;
	}
		suma=max(suma,zh);
	} 
	cout<<suma;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

