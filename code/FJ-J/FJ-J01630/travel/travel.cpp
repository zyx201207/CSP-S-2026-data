#include<iostream>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			int xx=s1[2]-'A'+1,xc=s2[2]-'A'+1;
			if((xx<=3&&xc<=3)||(xx>3&&xc>3)){
				cout<<"1";
				if(xx<=3&&xc<=3){
					if(xx==xc+1||xc==xx+1){
						cout<<"1";
					}else{
						cout<<"0";
					}
				}else if(xx>3&&xc>3){
					cout<<"1";
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
