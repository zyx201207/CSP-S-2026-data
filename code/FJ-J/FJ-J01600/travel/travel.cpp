#include<bits/stdc++.h>
using namespace std;
int c1,c2,pai1,pai2,li1,li2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1;
	cin>>s1;
	cin>>c2;
	cin>>s2;
	li1=s1[2]-'A'+1;
	li2=s2[2]-'A'+1;
	pai1=(s1[0]-'0')*10+(s1[1]-'0');
	pai2=(s2[0]-'0')*10+(s2[1]-'0');
	if(c1==c2){
		cout<<"1";
		if(pai1==pai2){
			cout<<"1";
			if((li1<=3&&li2<=3)||(li1>=4&&li2>=4)){
				cout<<"1";
				if((li1>=4&&li2>=4)||((li1<=3&&li2<=3)&&(max(li1-li2,li2-li1)==1))){
					cout<<"1";
				}else{
					cout<<"0";
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

