#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char q1,q2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	//问题1
	if(c1==c2){
		cout << 1;
	}
	else{
		cout << "0000";
		return 0;
	}
	
	//问题2
	string p1;   //排号 

	for(int i=0;i<2;i++){
		p1+=s1[i];
	}

	
	string p2;
	for(int i=0;i<2;i++){
		p2+=s2[i];
	}
	
	
	
	
	if(c1==c2&&p1==p2){
		cout << 1;
	}
	else{
		cout << "000";
		return 0;
	}
	
	//问题3
	q1=s1[2];
	q2=s2[2];

	if(  (q1=='C'&&q2=='D') || (q1=='D'&&q2=='C')  ){
		cout << "00";
		return 0;
	}
	else{
		cout << 1;
	}
	
	//问题4

	if(abs(int(q1-q2))==1){
		cout << 1;
	}
	else{
		cout << "0";
	}
	
	
	return 0;
}
