#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","W",stdout);
	string c1,s1,c2,s2;
	bool f=true;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<"1";
	else{
		cout<<"0";
		f=false;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&f){
		cout<<"1";
	}
	else{
		cout<<"0";
		f=false;
	}
	int x=s1[2]-'A'+1,y=s2[2]-'A'+1;
	if(f){
		if((x<=3&&y<=3)||((x>3&&x<=5)&&(y>3&&y<=5))){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
		if(x<y){
			int z=x;
			x=y;
			y=z;
		}
		if(x<=2){
			if(x-1==y){
				cout<<"1";
			}
			else{
				cout<<"0";
			}
		}
		else{
			if(x-1>=4&&x-1==y){
				cout<<"1";
			}
			else{
				cout<<"0";
			}
		}
	}
	else{
		cout<<"00";
	}
	return 0;
}
