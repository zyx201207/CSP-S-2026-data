#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,s,a,b;
	cin>>c>>s>>a>>b;
	if(c[0]==a[0]&&c[1]==a[1]){
		printf("%d","1");
		return 0;
	}
	else{
		printf("%d","0");
		return 0;
	}
	if(s[0]==b[0]&&s[1]==b[1]){
		printf("%d","1");
		return 0;
	}
	else{
		printf("%d","0");
		return 0;
	}
	
 } 
