#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	cin>>c1>>s1>>c2>>s2;//02 01A 02 01B
	bool a[4]={0,0,0,0};
	if(c1==c2)a[0]=1;//T
	else if(s1[0]==s2[0] && s1[1]==s2[1])a[1]=1;//T(?F?)
	else if((s1[2]>3 && s2[2]>3) || (s1[2]<4 && s2[2]<4))a[2]=1;//
	else if((s1[2]+1==s2[2] || s2[2]+1==s1[2]) && a[2]==1)a[3]=1;
	cout<<a[0]<<a[1]<<a[2]<<a[3];
	return 0;
}
