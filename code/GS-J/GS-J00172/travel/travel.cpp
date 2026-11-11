#include <iostream>
using namespace std;

string c1, s1, c2, s2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> c1>>s1>>c2>>s2;
	string ans="";
	
	if(c1!=c2)ans="0000";
	else{
		if(s1[0]!=s2[0]||s1[1]!=s2[1])ans="1000";
		else{
			int R=s1[2]-'A', X=s2[2]-'A';
			if(R==3)R++;
			if(X==3)X++;
			if((R-3)*(X-3)<0)ans="1100";
			else{
				if(R-X!=1&&R-X!=-1)ans="1110";
				else ans="1111";
			}
		}
	}
	
	cout << ans;
	
	return 0;
}
