#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,q1,q2,k1,k2;
bool a1=0,a2=0,a3=0,a4=0;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	q1=s1[0];
	q2=s2[0];
	q1+=s1[1];
	q2+=s2[1];
	k1=s1[2];
	k2=s2[2];
	if(c1==c2){
		a1=1;
		if(q1==q2){
			a2=1;
			if(k1>="A"&&k1<="C" && k2>="A"&&k2<="C"){
				a3=1;
				if(k1[0]+1==k2[0]||k2[0]+1==k1[0]||k1[0]-1==k2[0]||k2[0]-1==k1[0]){
					a4=1;
				}	
			}
			else if(k1=="D"&&k2=="F"){
				a3=1;
				a4=1;
			}
			else if(k1=="F"&&k2=="D"){
				a3=1;
				a4=1;
			}
		}
	}
	cout<<a1<<a2<<a3<<a4;
	return 0;
}
