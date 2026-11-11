#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("trevel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1[10],c2[10],c3[10],c4[10];
	cin>>c1>>c2>>c3>>c4;
	if(c1[0]==c3[0]&&c1[1]==c3[1]){
		cout<<"1";
		if(c2[0]==c4[0]&&c2[1]==c4[1]){
			cout<<"1";
			int a=c2[2]-'A'+1,b=c4[2]-'A'+1;
			if(a<=3&&b>=4||a>=4&&b<=3){
				cout<<"00";
			}else{
				cout<<"1";
				if(a-b==1||b-a==1){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
	
}
