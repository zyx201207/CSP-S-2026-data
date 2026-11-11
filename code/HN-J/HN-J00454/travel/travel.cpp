#include <bits/stdc++.h>
using namespace std;
int x,y,f=0,c[4];
string a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>a>>y>>b;
	if(x==y){
		c[0]=1;
		for(int i=0;i<3-1;i++){
			if(a[i]==b[i]){
				f++;
			}
		}
		if(f==2){
			c[1]=1;
			if((a[2]>='A'&&a[2]<='C'&&b[2]>='A'&&b[2]<='C')||(a[2]>='D'&&a[2]<='F'&&b[2]>='D'&&b[2]<='F')){
				c[2]=1;
				if(((a[2]=='D'&&b[2]=='F')||(a[2]=='F'&&b[2]=='D'))||(a[2]+1==b[2]&&a[2]!='D')||(a[2]-1==b[2]&&a[2]!='c')){
					c[3]=1;
				}
				else{
					c[3]=0;
				}
			}
			else{
				c[2]=0;
				c[3]=0;
			}
		}
		else{
			c[1]=0;
			c[2]=0;
			c[3]=0;
		}
	}
	else{
		c[0]=0;
		c[1]=0;
		c[2]=0;
		c[3]=0;
	}
	cout<<c[0]<<c[1]<<c[2]<<c[3];
	return 0;
}
