//GZ-J00653 遵义市汇川区周林学校 谭丞辰
#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) {
		cout<<"1";
		if((s1[0]==s2[0])&&(s1[1]==s2[1])) {
			cout<<"1";
			if(((int(s1[2])<=67)&&(int(s2[2])<=67))||((int(s1[2])>67)&&(int(s2[2])>67))) {
				cout<<"1";
				if(((int(s1[2])-int(s2[2]))==1)||((int(s2[2])-int(s1[2]))==1)) {
					cout<<"1";
				} else
					cout<<"0";
			} else
				cout<<"00";
		} else
			cout<<"000";
	} else
		cout<<"0000";

	fclose(stdin);
	fclose(stdout);
	return 0;
}

