//travel
#include <bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;

bool f1(){
	if (c1 == c2){
		return 1;
	}
	return 0;
}

bool f2(){
	if (s1[0] == s2[0] && s1[1] == s2[1]){
		return 1;
	}
	return 0;
}

bool f3(){
	if (((s1[2] >= 'A' && s1[2] <= 'C') && (s2[2] >= 'A' && s2[2] <= 'C')) || ((s1[2] >= 'D' && s1[2] <= 'F') && (s2[2] >= 'D' && s2[2] <= 'F'))){
		return 1;
	}
	return 0;
}

bool f4(){
	if ((s1[2] == 'D' && s2[2] == 'F') || (s2[2] == 'D' && s1[2] == 'F')){
		return 1;
	}
	if (abs(s1[2] - s2[2]) == 1){
		return 1;
	}
	return 0;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if (f1()){
		cout<<1;
	}else{
		cout<<0;
	}
	if (f1() && f2()){
		cout<<1;
	}else{
		cout<<0;
	}
	if (f1() && f2() && f3()){
		cout<<1;
	}else{
		cout<<0;
	}
	if (f1() && f2() && f3() && f4()){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
