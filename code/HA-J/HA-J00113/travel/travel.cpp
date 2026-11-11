#include<iostream>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)cout<<"0000";
	else{
		cout<<"1";
		if(s1[0]!=s2[0]||s1[1]!=s2[1])cout<<"000";
		else{
			cout<<"1";
			if((s1[2]-'A'<=2&&s2[2]-'A'>=3)||(s1[2]-'A'>=3&&s1[2]-'A'<=2))cout<<"00";
			else{
				cout<<"1";
				if(abs(int(s1[2]-s2[2]))!=1)cout<<"0";
				else cout<<"1";
			}
		}
	}
	return 0;
}
//背负最弱oier之名，我不能AC。 
