#include<iostream>
using namespace std;
string c1,s1,c2,s2;
int ck[10]={1,2,3,5,6,6};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			cout<<1;
			int a=ck[s1[2]-'A'],b=ck[s2[2]-'A'];
			if(a<=3 && b<=3 || a>=5 && b>=5){
				cout<<1;
				if(a-b==1 || a-b==-1){
					cout<<1;
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
