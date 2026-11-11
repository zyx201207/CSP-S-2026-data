#include <bits/stdc++.h>
using namespace std;
bool flag[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if (c1 == c2)
		flag[0]=true;
		
	string p1,p2;
	p1 =s1.substr(0,2);
	p2= s2.substr(0,2);
	if (p1 == p2 && flag[0])
		flag[1]=true;
	if (s1[2] >='A' && s1[2]<='C' && s2[2]>='A' && s2[2]<='C' && flag[1])
		flag[2]=true;
	if (s1[2] >='D' && s1[2]<='F' && s2[2]>='D' && s2[2]<='F' && flag[1])
		flag[2]=true;
	if ((s1[2] -1 == s2[2] || s1[2] +1 == s2[2]) && flag[2])
		flag[3]=true;
	for (int i=0;i<4;i++){
		cout<<flag[i];
	}
	return 0;
	
	
	
}
