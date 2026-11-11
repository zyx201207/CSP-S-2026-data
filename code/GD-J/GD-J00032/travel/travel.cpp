#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool a=(c1==c2),b=(s1[0]==s2[0]&&s1[1]==s2[1]);
	if(s1<s2) swap(s1,s2);
	bool c=(s1[2]<='C'&&s2[2]<='C'||s1[2]>='D'&&s2[2]>='D');
	int d=s1[2]-s2[2];
	if(s2[2]=='F') d--;
	if(a) cout<<'1';
	else cout<<'0';
	if(a&&b) cout<<'1';
	else cout<<'0';
	if(a&&b&&c) cout<<'1';
	else cout<<'0';
	if(a&&b&&c&&d==1) cout<<'1';
	else cout<<'0';
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
