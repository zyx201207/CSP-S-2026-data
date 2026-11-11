#include<iostream>
#include<string>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int a1=s1[2]-'A',a2=s2[2]-'A';
	if(c1==c2){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			if((a1<3&&a2<3)||(a1>2&&a2>2)){
				if(a1-a2==1||a2-a1==1)
					cout<<"1111";
				else
					cout<<"1110";
			}
			else
				cout<<"1100";
		}
		else
			cout<<"1000";
	}
	else
		cout<<"0000";
	return 0;
}
