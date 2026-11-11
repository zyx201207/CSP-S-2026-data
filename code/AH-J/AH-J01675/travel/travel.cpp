#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bool ans1=(c1==c2);
	bool ans2=(ans1&&s1.substr(0,2)==s2.substr(0,2));
	bool ans3=(ans2&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')));
	bool ans4=(ans3&&abs(s1[2]-s2[2])==1);
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
} 
