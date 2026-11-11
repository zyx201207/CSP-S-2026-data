//GZ-J00420 贵阳市第三实验中学 陈典伸
#include<bits/stdc++.h>
using namespace std;
	string c2,s2;
	int c1,s1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1){
		if(s2[0]==c2[0]&&s2[1]==c2[1]){
			if(c2[2]-s2[2]==1||s2[2]-c2[2]==1){
				cout<<"1111";
			}
			else if(c2[2]-'A'<3&&s2[2]-'A'<3)
				cout<<"1110";
			else{cout<<"1100";
			}
		}
		else{
			cout<<"1000";
		}
	}
	else{cout<<"0000";}
	return 0;
}
