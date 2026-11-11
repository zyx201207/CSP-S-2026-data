#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1 == c2){
		cout<<"1";
	}else{
		cout<<"0000";
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	string q1,q2;
	q1 = s1[0] + s1[1];
	q2 = s2[0] + s2[1];
	if(q1 == q2){
		cout<<"1";
	}else{
		cout<<"000";
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if((s1[2] == 'D'&&s2[2] == 'F')||(s1[2] == 'F'&&s2[2] == 'D')||(s1[2] == 'A'&&s2[2] == 'B')||(s1[2] == 'B'&&s2[2] == 'A')||(s1[2] == 'C'&&s2[2] == 'B')||(s1[2] == 'B'&&s2[2] == 'C')||(s1[2] == 'C'&&s2[2] == 'A')||(s1[2] == 'A'&&s2[2] == 'C')){
		cout<<"1";
	}else{
		cout<<"00";
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	int m1,m2;
	m1 = s1[2] - 'A' + 1;
	m2 = s2[2] - 'A' + 1;
	if((!(s1[2] == 'C'&&s2[2] == 'D'))&&max(m1,m2) - min(m1,m2) == 1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
