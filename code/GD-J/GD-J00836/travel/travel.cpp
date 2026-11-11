#include<iostream> 
using namespace std;
char s1[4],s2[4];
int c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<'1';
		if((s1[0]==s2[0])&&(s1[1]==s2[1])){
			cout<<'1';
			if(s1[2]=='F' || s1[2]=='D'){
				if(s2[2]=='F' || s2[2]=='D'){
					cout<<"11";
				}else{
					cout<<"00";
				}
			}else{
				if(s2[2]=='F' || s2[2]=='D'){
					cout<<"00";
				}else{
					cout<<'1';
					if(abs((s1[2]-'A')-(s2[2]-'A'))==1){
						cout<<'1';
					}else{
						cout<<'0';
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
