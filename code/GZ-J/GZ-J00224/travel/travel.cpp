//GZ-J00224 Í¿Ðù½Ü
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	bool q1=0,q2=0,q3=0,q4=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)q1=1;
	if(q1&&s1.substr(0,2)==s2.substr(0,2))q2=1;
	if(q2){
		if(s1[2]>='D'&&s2[2]>='D')q3=1;
		if(s1[2]<'D'&&s2[2]<'D')q3=1;
	}
	if(q3)if(s1[2]+1==s2[2]||s1[2]-1==s2[2])q4=1;
	cout<<q1<<q2<<q3<<q4<<endl; 
	return 0;
}
