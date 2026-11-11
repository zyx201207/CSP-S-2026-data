#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			int n1=s1[2]-'A',n2=s2[2]-'A';
			if(n1>=0&&n2<=2){
				cout<<"1";
				if(n1-n2==1||n1-n2==-1){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else if(n1>=3&&n2<=4){
				cout<<"1";\
				if(n1-n2==1||n1-n2==-1){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
