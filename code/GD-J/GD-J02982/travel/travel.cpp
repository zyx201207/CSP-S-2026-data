#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int t1=(s1[0]-48)*10+s1[1]-48;
	int t2=(s2[0]-48)*10+s2[1]-48;	
	
	if(c1==c2){
		cout << "1";
		if(t1==t2){
			cout << "1";
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
				cout << "1";
				char c1=s1[2],c2=s2[2];
				if((abs(c1-c2)==1)||(c1=='D'&&c2=='F')||(c2='F'&&c2=='D')) cout << "1";
				else cout << "0";
			} 
			else cout << "00";
		} 
		else cout << "000";
	} 
	else cout << "0000";
	return 0;
}
