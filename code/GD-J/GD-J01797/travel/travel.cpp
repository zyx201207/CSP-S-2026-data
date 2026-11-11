#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool l1=0,l2=0,l3=0,l4=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		l1=true;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			l2=true;
			char q1=s1[2];
			char q2=s2[2];
			if(((q1=='A'||q1=='B'||q1=='C')&&(q2=='A'||q2=='B'||q2=='C')) || ((q1=='D'||q1=='F')&&(q2=='D'||q2=='F'))){
				l3=true;
				if( (int(q1) == int(q2)+1)||(int(q1) == int(q2)-1) ){
					l4=true;
				}
			}
		}
	}
	string pr1="";
	pr1=pr1+char(l1+48)+char(l2+48)+char(l3+48)+char(l4+48);
	cout<<pr1;
	
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
