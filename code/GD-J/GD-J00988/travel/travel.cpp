#include <iostream>
#include <map>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#define ll long long
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string ans;
	bool inc=0;
	if(c1!=c2) {
		cout<<"0000"<<endl;
		return 0;
	} 
	if(s2[0]!=s1[0]||s2[1]!=s1[1]){
		cout<<"1000"<<endl;
		return 0;
	}
	if(!((s2[2]>='D'&&s1[2]>='D')||(s2[2]<='C'&&s1[2]<='C'))){
		cout<<"1100"<<endl;
		return 0;
	}
	if(!((s2[2]>='D'&&s1[2]>='D')||((s2[2]<='C'&&s1[2]<='C')&&abs(int(s2[2]-s1[2]))==1))){
		cout<<"1110"<<endl;
		return 0;
	}
	else cout<<"1111"<<endl;
	return 0;
}

