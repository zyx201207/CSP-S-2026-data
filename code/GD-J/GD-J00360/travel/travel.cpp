#include<bits/stdc++.h>
using namespace std;
int h1,h2,h3,h4,c1,c2;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s1>>s2>>s3>>s4;
	h1=(s1[0]-'0')*10+(s1[1]-'0');
	h2=(s3[0]-'0')*10+(s3[1]-'0');
	h3=(s2[0]-'0')*10+(s2[1]-'0');
	h4=(s4[0]-'0')*10+(s4[1]-'0');
	c1=s2[2]-'A';
	c2=s4[2]-'A';
	if(h1==h2){
		cout<<"1";
		if(h3==h4){
			cout<<"1";
			if((c1>=3&&c2>=3)||(c1<3&&c2<3)){
				cout<<"1";
				if(abs(c1-c2)==1)cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
