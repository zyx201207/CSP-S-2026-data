#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,c1,c2;
	cin >>c1>>s1>>c2>>s2;
	int p1,p2,z1,z2;
	p1=(s1[0]-'0')*10+(s1[1]-'0');
	p2=(s2[0]-'0')*10+(s2[1]-'0');
	z1=s1[2]-'A';
	z2=s2[2]-'A';
	if(c1==c2){
		cout <<1;
		if(p1==p2){
			cout <<1;
			if((z1<3&&z2<3)||(z1>2&&z2>2)){
				cout <<1;
				int maxx=max(z1,z2);
				int minn=min(z1,z2);
				if(maxx==minn+1){
					cout <<1;
				}else{
					cout <<"0";
					return 0;
				}
			}else{
				cout <<"00";
				return 0;
			}
		}else{
			cout <<"000";
			return 0;
		}
	}else{
		cout <<"0000";
		return 0;
	}
	return 0;
}
