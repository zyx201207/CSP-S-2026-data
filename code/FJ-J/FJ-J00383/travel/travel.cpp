#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if (s1[2]=='D') s1[2]='E';
	if (s2[2]=='D') s2[2]='E';
	if (c1!=c2) cout<<"0000";
	else{
		if (s1[0]!=s2[0]) cout<<"1000";
		else if (s1[1]!=s2[1]) cout<<"1000";
		else{
			if (s1[2]>'D' && s2[2]<'D' || s1[2]<'D' && s2[2]>'D') cout<<"1100";
			else{
				if (s1[2]-s2[2]==1 || s1[2]-s2[2]==-1) cout<<"1111";
				else cout<<"1110";
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
