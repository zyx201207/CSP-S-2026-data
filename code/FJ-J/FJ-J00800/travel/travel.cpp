#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool tc=(c1==c2);
	cout<<tc;
	bool tp=(tc&&s1[0]==s2[0]&&s1[1]==s2[1]);
	cout<<tp;
	map<char,int> m={{'A',0},
	{'B',0},{'C',0},{'D',1},{'E',1}};
	bool tgc=(tp&&m[s1[2]]==m[s2[2]]);
	cout<<tgc;
	bool xl=(tgc&&abs(s1[2]-s2[2])==1);
	cout<<xl<<endl;
}
