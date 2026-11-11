#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	int n=s1.size(),n2=s2.size();
	for(int i=0;i<n;i++){
		if(s1[i]!=s3[i]){cout<<"0000";return 0;}
	}
	for(int i=0;i<n2-1;i++){
		if(s2[i]!=s4[i]){cout<<"1000";return 0;}
	}
	int c1,c2;
	if(s2[2]>='A'&&s2[2]<='C') c1=1;
		else c1=2;
	if(s4[2]>='A'&&s4[2]<='C') c2=1;
		else c2=2;
	if(c1!=c2){ cout<<"1100";return 0;} 
	
	int k=abs(s2[2]-s4[2]);
	if(k!=1){ cout<<"1110";return 0;} 
		else {cout<<"1111";}




	return 0;
}
