#include<bits/stdc++.h>
using namespace std;
string r1,r2,x1,x2;
bool a,b,c,d,e;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>r1>>r2>>x1>>x2;
	if(r1==x1){
		a=1;
		printf("1");
		if(r2[0]==x2[0]&&r2[1]==x2[1]){
			printf("1");b=1;
			if((x2[2]>='A'&&x2[2]<='C')&&(r2[2]>='A'&&r2[2]<='C')||(x2[2]>='D'&&x2[2]<='F')&&(r2[2]>='D'&&r2[2]<='F')){
				printf("1");c=1;
				char a,b;
				if(x2[2]>r2[2]){
					a=x2[2];
					b=r2[2];
				}
				if(x2[2]<r2[2]){
					a=r2[2];
					b=x2[2];
				}
				if((int(a)-int(b))==1) printf("1");d=1;
			}
		}
	}
	if(!a) printf("0");
	if(!b) printf("0");
	if(!c) printf("0");
	if(!d) printf("0");
	return 0;
} 
