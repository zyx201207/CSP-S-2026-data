#include<bits/stdc++.h> 
using namespace std;
int c1,c2; 
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	cout<<(c1==c2);
	string ss1,ss2;
	ss1=s1[0]+s1[1];
	ss2=s2[0]+s2[1];
	cout<<(c1==c2&&ss1==ss2);
	cout<<(c1==c2&&ss1==ss2&&(s1[2]<='C'&&s2[2]<='C'|| s1[2]>='D'&&s2[2]>='D'));
	cout<<((s1[2]-s2[2]==1 || s2[2]-s1[2]==1)&&c1==c2&&ss1==ss2&&(s1[2]<='C'&&s2[2]<='C'|| s1[2]>='D'&&s2[2]>='D'));
	fclose(stdin);
	fclose(stdout);
	
	
	return 0;
}
