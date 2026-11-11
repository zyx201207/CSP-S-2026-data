#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a,c;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a=(c1[0]-'0')*10+c1[1]-'0';
	c=(c2[0]-'0')*10+c2[1]-'0';
	if(a==c){
		cout<<"1";
		a=(s1[0]-'0')*10+s1[1]-'0';
		c=(s2[0]-'0')*10+s2[1]-'0';
		if(a==c){
			cout<<"1";
			a=s1[2]-'A';
			c=s2[2]-'A';
			if(a<=2&&c>=3){
				cout<<"00";
			}else{
				if(a>=3&&c<=2){
					cout<<"00";
				}else{
					cout<<"1";
					if(a-c==1||c-a==1){
						cout<<"1";
					}else{
						cout<<"0"; 
					}
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
