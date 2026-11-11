#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1,c2,c3,c4;
	cin >> c1 >> c2;
	int a1,a2,b1,b2;
	if(c1 == '0'){
		a1 = c2-'0';
	}
	else{
		a1 = (int)(c1-'0')*10+(c2-'0');
	}
	cin >> c1 >> c2 >> c3;
	if(c1 == '0'){
		b1 = c2-'0';
	}
	else{
		b1 = (int)(c1-'0')*10+(c2-'0');
	}
	cin >> c1 >> c2;
	if(c1 == '0'){
		a2 = c2-'0';
	}
	else{
		a2 = (int)(c1-'0')*10+(c2-'0');
	}
	cin >> c1 >> c2 >> c4;
	if(c1 == '0'){
		b2 = c2-'0';
	}
	else{
		b2 = (int)(c1-'0')*10+(c2-'0');
	}
	if(a1 != a2)
	{
		cout << "0000";
		return 0;
	}
	if(b1 != b2){
	
		cout << "1000";
		return 0;
	}
	
	if((c3 == 'D' && c4 == 'F' )|| (c3 == 'F' && c4 == 'D') || (c3 == 'A' && (c4 == 'B' || c4 == 'C')) || 
	(c3 == 'B' && (c4 == 'A' || c4 == 'C')) || (c3 == 'C' && (c4 == 'A' || c4 == 'B')));
	else{
		cout << "1100";
		return 0;
	}
	if((c3 == 'A' && c4 == 'B') || (c3 == 'B' && (c4 == 'A' || c4 == 'C')) || (c3 == 'C' && c4 == 'B')
	|| (c3 == 'D' && c4 == 'F') || (c3 == 'F' && c4 == 'D'));
	else {
		cout << "1110";
		return 0;
	}
	cout << "1111";
	return 0;
	
} 
