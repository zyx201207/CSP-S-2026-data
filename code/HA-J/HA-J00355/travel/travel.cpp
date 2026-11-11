#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int k=0;
	string c1,c2,s1,s2,q1,q2;
	cin>>c1>>s1>>c2>>s2;
	q1=s1;q2=s2;
	if(c1==c2){
		cout<<"1";
		k++;
	}
		
	else 
		cout<<"0";
	
	s1.erase(2,3);
	s2.erase(2,3);
	if(s1==s2&&k==1){
		cout<<"1";
		k++;
	}
	else
		cout<<"0";
	
	q1.erase(0,2);
	q2.erase(0,2);
	if(q1[0]-'A'<=2&&q2[0]-'A'<=2&&k==2)
		cout<<"1";
	else 
		if(q1[0]-'A'>=3&&q2[0]-'A'>=3){
			cout<<"1"<<"1";
			return 0;
		}
		else{
			cout<<"0"<<"0";
			return 0;
		}
		
	if(q1[0]-q2[0]<=1||q1[0]-q2[0]>=-1)
		cout<<"1";
	else 
		cout<<"0";
	return 0;

}
