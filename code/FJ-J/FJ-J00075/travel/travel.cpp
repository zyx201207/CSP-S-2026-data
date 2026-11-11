#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		int j1=(s1[0]-'0')*10+(s1[1]-'0');
		int j2=(s2[0]-'0')*10+(s2[1]-'0');
		int i1=s1[2]-'A',i2=s2[2]-'A';
		if(j1==j2){
			cout<<1;
			if((i1<3&&i2<3)||(i1>2&&i2>2)){
				cout<<1;
				int d=abs(i1-i2);
				if((i1<3&&i2<3&&d==1)||(i1>2&&i2>2)){
					cout<<1;
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000"; 
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
