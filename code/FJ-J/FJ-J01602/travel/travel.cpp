#include<bits/stdc++.h>
using namespace std;
char rc[10],rs[10];
char xc[10],xs[10];
int a[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	memset(a,0,sizeof(a));
	cin>>rc>>rs>>xc>>xs;
	int f=1;
	for(int i=0;i<2;i++){
		if(xc[i]!=rc[i]) f=0;
	}
	a[0]=f;
	if(f){
		int f1=1;
		for(int i=0;i<2;i++){
			if(rs[i]!=xs[i]) f1=0;
		}
		a[1]=f1;
		if(f1){
			if(rs[2]<='C'&&rs[2]>='A'&&xs[2]<='C'&&xs[2]>='A'){
				a[2]=1;
				if(a[2]==1){
					if(abs(rs[2]-xs[2])==1){
						a[3]=1;
					}
				}
			}
			else if(rs[2]<='F'&&rs[2]>='D'&&xs[2]<='F'&&xs[2]>='D'){
				a[2]=1;
				a[3]=1;
			}
		}
	}
	for(int i=0;i<=3;i++){
		cout<<a[i];
	}
	return 0;
}
