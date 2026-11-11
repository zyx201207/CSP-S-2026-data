#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	
	cout<<int(c1[0]==c2[0]&&c1[1]==c2[1]);
	
	int n1=int(s1[0]-'0')*10+int(s1[1]-'0');
	int n2=int(s2[0]-'0')*10+int(s2[1]-'0');
	
	cout<<int((c1[0]==c2[0]&&c1[1]==c2[1]) && (n1==n2));
	cout<<int((c1[0]==c2[0]&&c1[1]==c2[1]) && (n1==n2) && ((s1[2]<'D')==(s2[2]<'D')));
	cout<<int((c1[0]==c2[0]&&c1[1]==c2[1]) && (n1==n2) && ((s1[2]<'D')==(s2[2]<'D')) && ((int)s1[2]+1==(int)s2[2] || (int)s1[2]-1==(int)s2[2]));
	
	return 0;
}
