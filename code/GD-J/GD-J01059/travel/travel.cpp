#include<bits/stdc++.h>
using namespace std;
int x1,x2,y1,y2,z1,z2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,c1,s2,c2;
	cin>>s1>>c1>>s2>>c2;
	x1=(s1[0]-'0'+0)*10+(s1[1]-'0'+0);
	x2=(s2[0]-'0'+0)*10+(s2[1]-'0'+0);
	y1=(c1[0]-'0'+0)*10+(c1[1]-'0'+0);
	y2=(c2[0]-'0'+0)*10+(c2[1]-'0'+0);
	z1=c1[2]-'A'+1,z2=c2[2]-'A'+1;
	if(x1!=x2)cout<<"0000";
	else{
		cout<<'1';
		if(y1!=y2)cout<<"000";
		else{
			cout<<'1';
			if((z1>=4&&z2<=3)||(z1<=3&&z2>=4))cout<<"00";
			else{
				cout<<'1';
				if(abs(z1-z2)>1)cout<<'0';
				else cout<<'1';
			}
		}
	}
	cout<<endl;
	return 0;
}
