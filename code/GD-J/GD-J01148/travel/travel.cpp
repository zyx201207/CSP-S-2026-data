#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool a=(c1==c2);
	cout<<a;
	bool b=(a&&s1[0]==s2[0]&&s1[1]==s2[1]);
	cout<<b;
	bool c=(b&&(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='E'&&s2[2]>='D'&&s2[2]<='E'));
	cout<<c;
	bool d=(1==abs(s1[2]-s2[2]));
	cout<<(c&&d);
	return 0;
}
