#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int n1[5];
	int n2[5];
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1!=c2){
		cout << 0;
	}
	
	else{
		cout << 1;
	}
	for(int i = 1;i <= 3;i++){
		n1[i] = s1[i];
		n2[i] = s2[i];
	}
		

	if(n1[1] + n1[2]== n2[1]+n2[2])
		cout << 1;
	else
		cout << 0;
	
	if((n1[3]<='C'&&n2[3] <='C')||(n1[3]>'C'&&n2[3]>'C'))
		cout << 1;
		if(n1[1]+n1[2]==n2[1]+n2[2]&&(n1[3]-n2[3]==1||n2[3]-n1[3]==1))
			cout << 1;
	else
		cout << "00";
	
	
	
	
	
	
	
}
