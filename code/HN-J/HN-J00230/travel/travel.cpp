#include<bits/stdc++.h>
using namespace std;
int c1,c2;
int a,b,c,d;
string s1,s2,ans="0000";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<ans;
		return 0;
	}
	ans[0]='1';
	a=(s1[0]-'0')*10+(s1[1]-'0');
	b=(s2[0]-'0')*10+(s2[1]-'0');
	if(a!=b){
		cout<<ans;
		return 0;
	}
	ans[1]='1';
	c=s1[2]-'A';
	d=s2[2]-'A';
	if(!(c<=2 and d<=2 or c>2 and d>2)){
		cout<<ans;
		return 0;
	}
	ans[2]='1';
	if(abs(c-d) == 1) ans[3]='1';
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
