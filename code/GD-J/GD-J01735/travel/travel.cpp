#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool ga[6][20];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	char n1,n2;
	n1==s1[2];
	n2==s2[2];
	char g1,g2;
	g1=s1[2];
	g2=s2[2];
	char w1=s1[0]+s1[1];
	char w2=s2[0]+s2[1];
	bool q1=0,q2=0;
	if(g1<='C')q1=1;
	if(g2<='C')q2=1;
	if(c1==c2){
		cout<<"1";
		if(w1==w2){
			cout<<"1";
			if(q1==q2){
				cout<<"1";
				
			}else{
				cout<<"0";
			}
			if(w1==w2+1||w1+1==w2||g1+1==g2||g1==g2+1)cout<<"1";
				else cout<<"0";
		}else{
			cout<<"000";
		}
	}
	else cout<<"0000";
	return 0;
} 
