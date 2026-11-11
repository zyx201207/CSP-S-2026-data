#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
string c1,s1,c2,s2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(stoi(c1)==stoi(c2))
		cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	if(stoi(s1.substr(0,2))==stoi(s2.substr(0,2))){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if((s1[2]>='D'&&s2[2]<='C')||(s2[2]>='D'&&s1[2]<='C')){
		cout<<"00";
		return 0;
	}else
		cout<<"1";
	if(abs(s1[2]-s2[2])==1)
		cout<<"1";
	else
		cout<<"0";
	return 0;
}
