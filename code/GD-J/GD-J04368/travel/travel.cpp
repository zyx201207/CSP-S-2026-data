#include <bits/stdc++.h> 
using namespace std;
#define cin fin
#define cout fout
int main(){
	ifstream fin("travel.in");
	ofstream fout("travel.out");
	string c1,s1,c2,s2,p1,p2,q1,q2;
	int a,b;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		p1=s1.substr(0,2);
		p2=s2.substr(0,2);
		if(p1==p2){
			cout<<"1";
			q1=s1.substr(2,1);
			q2=s2.substr(2,1);
			if(q1=="A"||q1=="B"||q1=="C") a=1;
			else a=2;
			if(q2=="A"||q2=="B"||q2=="C") b=1;
			else b=2;
			if(a==b){
				cout<<"1";
				if(a==2) cout<<"1";
				else if((q1=="A"&&q2=="C")||(q1=="C"&&q2=="A"))
						cout<<"0";
						else cout<<"1";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else{
		cout<<"0000";
	}
	return 0;
}
