#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	} else{
		cout<<"1";
		int pai_1=(s1[0]-'0')*10+(s1[1]-'0');
		int pai_2=(s2[0]-'0')*10+(s2[1]-'0');
		if(pai_1!=pai_2){
			cout<<"000";
		}else{
			cout<<"1";
			int zuo_1=s1[2]-'A'+1;
			int zuo_2=s2[2]-'A'+1;
			if((zuo_1<=3&&zuo_2<=3)||(zuo_1>=4&&zuo_2>=4)){
				cout<<"1";
				if(abs(zuo_1-zuo_2)==1){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}
	}
	return 0;
} 
