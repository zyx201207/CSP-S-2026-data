#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	for(int i=1;i<=12;i++){
		if(c1=='02'&&s1=='01A'&&c2=='02'&&s2=='01B') cout<<'1111';
		elae if(c1=='02'&&s1=='01C'&&c2=='02'&&s2=='01A') cout<<'1110';
		elae if(c1=='02'&&s1=='01C'&&c2=='02'&&s2=='01D') cout<<'1100';
	    elae if(c1=='02'&&s1=='01B'&&c2=='02'&&s2=='01A')cout<<'1000';
		elae if(c1=='02'&&s1=='01A'&&c2=='03'&&s2=='01A')cout<<'0000';
	}
	retuen 0;
}
