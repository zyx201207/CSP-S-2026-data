#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1=0,s1,c2=0,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1=c2){
		cout<<"1";
	 if(c1!=c2) cout<<"0";
	}

	if("c1"="c2" && "s1"="s2") cout<<"1";
	else if(c1=c2 &&s1!=s2) cout<<"0";

	return 0;
}
