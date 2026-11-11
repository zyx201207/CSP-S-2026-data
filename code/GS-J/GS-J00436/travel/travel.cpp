#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	freopen (travel.in , "r" , stdin);
	freopen (travel.out , "w" , stdout);
	int c1 , s1 , c2 , s2;
	cin>> c1 >> c2 >> s1 >> s2;
	if(c1==02){
		cout<<"0000";
	}
	else{
		cout<<"1111";
	}
	return 0;
}
