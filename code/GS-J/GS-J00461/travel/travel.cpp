#include <bits/stdc++.h>
using namespace std;
int m,n;
string c1[2],s1[3],c2[2],s2[3];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[1]==c2[1]&&c1[2]&&c2[2])
		cout<<"1";
		else 
			{cout<<"0000";}
		if(s1[1]==s2[1]&&s1[2]==s2[2])
		cout<<"1";
		else
			{cout<<"000";
		}
			if(s1[3]!=s2[3]&&++s1==s2)
			cout<<"1";
			else{cout<<"00";
			}
			if(s1==s2+1)
			cout<<"1";
		return 0;
}
