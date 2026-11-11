#include<bits/stdc++.h>
using namespace std;
char c1[10],s1[10],c2[10],s2[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]!=c2[0]||c1[1]!=c2[1])
		cout<<"0000"<<"\n";
	else
		if(s1[0]!=s2[0]||s1[1]!=s2[1])
			cout<<"1000"<<"\n";
		else
			if((s1[2]-'A'+1<=3&&s2[2]-'A'+1>=4)||(s2[2]-'A'+1<=3&&s1[2]-'A'+1>=4))
				cout<<"1100"<<"\n";
			else
				if(s1[2]-'A'+2==s2[2]-'A'+1||s1[2]-'A'==s2[2]-'A'+1)
					cout<<"1111"<<"\n";
				else
					cout<<"1110"<<"\n";
	return 0;
}
