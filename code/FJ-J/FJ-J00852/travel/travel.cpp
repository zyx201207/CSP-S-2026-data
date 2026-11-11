#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0);cout.tie(0);
	
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int rc=(c1[0]-'0')*10+(c1[1]-'0'),xc=(c2[0]-'0')*10+(c2[1]-'0');
	int rs1=(s1[0]-'0')*10+(s1[1]-'0'),xs1=(s2[0]-'0')*10+(s2[1]-'0');
	int rs2=int(s1[2]),xs2=int(s2[2]);
	if(rc!=xc)cout<<"0000";
	else{
		cout<<"1";
		if(rs1!=xs1)cout<<"000";
		else{
			cout<<"1";
			if(rs2>=xs2)swap(rs2,xs2);
			if(rs2>=65&&rs2<=67){
				if(xs2>=68)cout<<"00";
				else cout<<"1"<<(!(rs2==65&&xs2==67));
			}
			else cout<<(xs2==70)<<(xs2==70);
		}
	}
	
	return 0;
}
