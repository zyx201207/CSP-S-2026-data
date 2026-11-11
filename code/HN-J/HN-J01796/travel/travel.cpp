#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	int a,b,c,d;
	if((x1[0]-'0')*10+(x1[1]-'0')==(x2[0]-'0')*10+(x2[1]-'0')){
		a=1;
		if((y1[0]-'0')*10+(y1[1]-'0')==(y2[0]-'0')*10+(y2[1]-'0')){
			b=1;
			if((y1[2]-'A'<3&&y2[2]-'A'<3)||(y1[2]-'A'>=3&&y2[2]-'A'>=3)){
				c=1;
				if(((y1[2]-'A')-(y2[2]-'A')==1||(y1[2]-'A')-(y2[2]-'A')==-1)||((y2[2]-'A'==5||y1[2]-'A'==5)&&(y1[2]-'A')-(y2[2]-'A')==2)||((y2[2]-'A'==5||y1[2]-'A'==5)&&(y1[2]-'A')-(y2[2]-'A')==-2)){
					d=1;
				}else{
					d=0;
				}
			}else{
				c=0;
				d=0;
			}
		}else{
			b=0;
			c=0;
			d=0;
		}
	}else{
		a=0;
		b=0;
		c=0;
		d=0;
	}
	cout<<a<<b<<c<<d;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
