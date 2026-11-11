#include<bits/stdc++.h>
using namespace std;

char c1[2],s1[3],c2[2],s2[3];
int x1,yy1,x2,yy2;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	x1=(c1[0]-48)*10+(c1[1]-48);
	x2=(c2[0]-48)*10+(c2[1]-48);
	if(s1[2]=='F')	s1[2]='E';
	if(s2[2]=='F')	s2[2]='E';
	for(int i=0;i<3;i++){
		if(i!=2){
			yy1=yy1*10+(s1[i]-48);
			yy2=yy2*10+(s2[i]-48);
		}else{
			yy1=yy1*10+(s1[i]-64);
			yy2=yy2*10+(s2[i]-64);
		}
	}
	if(x1==x2){
		cout<<1;
		if((yy1/10)==(yy2/10)){
			cout<<1;
			if((yy1%10>=1&&yy1%10<=3&&yy2%10>=1&&yy2%10<=3)||(yy1%10>=4&&yy1%10<=5&&yy2%10>=4&&yy2%10<=5)){
				cout<<1;
				if(abs(yy1-yy2)==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
