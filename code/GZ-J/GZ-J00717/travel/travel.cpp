//GZ-J00717 Ñî½ðÑ× ºëÒãÖÐÑ§ 
#include <bits/stdc++.h>
using namespace std;

string s1,c1,s2,c2,s;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);	
	cin>>s1>>c1>>s2>>c2;
	if(s1==s2) {
		s+='1';
		if(c1[0]==c2[0]&&c1[1]==c2[1]){
			s+='1';
			if(c1[2]-'A'<=2&&c2[2]-'A'<=2||c1[2]-'A'>=3&&c2[2]-'A'>=3){
				s+='1';
				if(c1[2]-c2[2]==1||c1[2]-c2[2]==-1||c1[2]=='D'&&c2[2]=='F'||c1[2]=='F'&&c2[2]=='D')
					s+='1';
				else s="1110";
			}
			else s="1100";
		}
		else s="1000";
	}
	else s="0000";
	cout<<s<<endl;
	return 0;
}
