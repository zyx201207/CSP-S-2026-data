#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,x,y;
char u,v;
int a[15]={0};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	x="";
	y="";
	if(c1==c2){
		a[1]=1;
		for(int i=0;i<=1;i++){
			x+=s1[i];
			y+=s2[i];
		}
		u=s1[2];
		v=s2[2];
		if(x==y){
			a[2]=1;
			if((u<='C' and v<='C') || (u>='D' and v>='D')){
				a[3]=1;
				int l=abs(u-v);
				if(l==1){
					a[4]=1;
				}
			}
		}
	}
	for(int i=1;i<=4;i++){
		cout<<a[i];
	}
	return 0;
}
