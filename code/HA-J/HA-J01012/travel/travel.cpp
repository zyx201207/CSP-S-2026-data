#include<bits/stdc++.h>
using namespace std;
char a[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x1,x2,y1,y2;
	char z1,z2;
	cin>>x1>>y1>>z1>>x2>>y2>>z2;
	if(x1==x2){
		a[1]='1';
		if(y1==y2){
			a[2]='1';
			if(z1<='C'&&z2<='C'||z1>='D'&&z2>='D'){
				a[3]='1';
				if(abs(z1-z2)==1){
					a[4]='1';
				}
				else{
					a[4]='0';
				}
			}
			else{
				a[3]='0';
				a[4]='0';
			}
		}
		else{
			a[2]='0';
			a[3]='0';
			a[4]='0';
		}
	}
	else{
		a[1]='0';
		a[2]='0';
		a[3]='0';
		a[4]='0';
	}
	for(int i=1;i<=4;i++){
		cout<<a[i];
	}
	return 0;
}
