#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool f1,f2,f3;
int main(){
	freopen("travel.in","r",stdin),freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(s1[2]>s2[2]) swap(s1[2],s2[2]);
	if(c1==c2) f1=1;
	if(s1[0]==s2[0] && s1[1]==s2[1]) f2=f1;
	if(s2[2]<='C' || s1[2]>='D') f3=f2;
	cout<<f1<<f2<<f3;
	cout<<(f3 && (s1[2]+1==s2[2] || (s1[2]=='D' && s2[2]=='F')));
	fclose(stdin),fclose(stdout);
	return 0;
} 
