#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int x1,x2,y1,y2;
	x1=(int)s1[0]-48;
	x2=(int)s1[1]-48;
	y1=(int)s2[0]-48;
	y2=(int)s2[1]-48;
	char a1,a2;
	a1=s1[2];
	a2=s2[2];
	if(c1==c2){
		cout<<"1";
		if(x1==y1 && x2==y2){
			cout<<"1";
			if((int)a1>=65&&(int)a1<=67){
				if((int)a2>=65&&(int)a2<=67){
					cout<<"1";
					if((int)a1-(int)a2==1||(int)a2-(int)a1==1){
						cout<<"1";
					}
					else{
						cout<<"0";
					}
				}
				else{
					cout<<"00";
				}
			}
			else{
				if((int)a2==68||(int)a2==70){
					cout<<"11";
				}
				else{
					cout<<"00";
				}
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
