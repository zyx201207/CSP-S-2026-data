#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){//两张车票对应的座位是否在同一节车厢 
		cout << "1";
	}
	else{
		cout << "0";
	}
	if(s1[0] == s2[0] && s1[1] == s2[1]){//两张车票对应的座位是否在同一节车厢的同一排 
		cout << "1";
	}
	else{
		cout << "0";
	}
	if(s1[2] != s2[2])
	{
		cout << "1";
	}
	else{
		cout << "0";
	}
	if(s1[2] != s2[2])
	{
		cout << "1";
	}
	else{
		cout << "0";
	}
	fclose(stdin);
	fclose(stdin);
	return 0;
}