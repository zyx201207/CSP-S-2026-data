#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	bool flag1,flag2;
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		cout<<"1000";
		return 0;
	}
	int a=s1[2];
	int b=s2[2];
	if((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s1[2]=='C')){
		cout<<"1100";
		return 0;
	}
	if(abs(a-b)!=1){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
