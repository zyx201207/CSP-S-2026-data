#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if(s1[0]!=s2[0]){
		cout<<"000";
		return 0;
	}
	if(s1[1]!=s2[1]){
		cout<<"000";
		return 0;
	}
	cout<<"1";
	int a=s1[2]-'A'+1;
	int b=s2[2]-'A'+1;
	if(a==6)a-=1;
	if(b==6)b-=1;
	if(a<=3&&b>=4){
		cout<<"00";
		return 0;
	}
	if(b<=3&&a>=4){
		cout<<"00";
		return 0;
	}
	cout<<"1";
	if(abs(a-b)==1)cout<<"1";
	if(abs(a-b)!=1)cout<<"0";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
