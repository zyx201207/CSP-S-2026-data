#include<bits/stdc++.h>
using namespace std;
int z1,z2,a1,a2;
int c1,c2; 
string s1,s2,x1,x2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x1>>s1>>x2>>s2;
	z1=(x1[0]-'0')*10+(x1[1]-'0');
	z2=(x2[0]-'0')*10+(x2[1]-'0');
	c1=s1[2]-'A';
	c2=s2[2]-'A';
	a1=(s1[0]-'0')*10+(s1[1]-'0');
	a2=(s2[0]-'0')*10+(s2[1]-'0');
	if(z1==z2){
		cout<<1;
		if(a1==a2){
			cout<<1;
			if(c1<3&&c2<3){
				cout<<1;
				if(c1==1||c2==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else if(c1>2&&c2>2){
				cout<<"11";
				return 0;
			}else{
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	
	return 0;
}