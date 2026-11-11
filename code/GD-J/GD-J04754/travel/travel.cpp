#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2)
		cout << 1;
	else{
		cout << "0000";
		return 0;
	}
	string d1 = "",d2 = "";
	char w1,w2;
	for(int i = 0; i < s1.size(); i++){
		if((s1[i] >= 'A' && s1[i] <= 'Z'))
			w1 = s1[i];
		else
			d1 += s1[i];
	}
	for(int i = 0; i < s2.size(); i++){
		if((s2[i] >= 'A' && s2[i] <= 'Z'))
			w2 = s2[i];
		else
			d2 += s2[i];
	}
	bool f = 1;
	if(d1 == d2){
		cout << 1;
	}else{
		cout << 0;
		f = 0;
	}
	bool f2 = 1;
	if(w1 >= 'A' && w1 <= 'C' && w2 >= 'A' && w2 <= 'C'){
		if(f == 0){
			f2 = 0;
			cout << 0;
		}else{
			cout << 1;
		}
	}else if(w1 >= 'D' && w1 <= 'E' && w2 >= 'D' && w2 <= 'E'){
		if(f == 0){
			f2 = 0;
			cout << 0;
		}else{
			cout << 1;
		}
	}else{
		f2 = 0;
		cout << 0;
	}
	if(w1 + 1 == w2 || w1 - 1 == w2){
		if(f2 == 0){
			cout << 0;
		}else{
			cout << 1;
		}
	}else
		cout << 0;
	return 0;
} 
