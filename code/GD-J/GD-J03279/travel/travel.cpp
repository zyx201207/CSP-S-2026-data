#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(s1.substr(0,2)!=s2.substr(0,2)){
		cout<<"1000";
		return 0;
	}
	bool d1=0,d2=0;
	d1=s1.substr(2,1)>="D";
	d2=s2.substr(2,1)>="D";
	if(d1!=d2){
		cout<<"1100";
		return 0;
	}
	if(d1==0&&(s1.substr(2,1)!="B"&&s2.substr(2,1)!="B")){
		cout<<"1110";
	}else{
		cout<<"1111";
	}
	return 0;
}
