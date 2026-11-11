#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char s1,c1,s2,c2;
	cin>>s1>>c1>>s2>>c2;
	if(s1=s2){
		if(c1==c2)cout<<"1111";
		else cout<<"1000";
		}
	else cout<<"0000";
	return 0;
}
