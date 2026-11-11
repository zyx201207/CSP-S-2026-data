#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1==c2) cout << 1;
	else{
		cout << "0000";
		return 0;
	}
	string a;
	string b;
	a=a+s1[0];
	a=a+s1[1];
	b=b+s2[0];
	b=b+s2[1];
	if (a==b) cout << 1;
	else {
		cout << "000";
		return 0;
	}
	string x,y;
	x=x+s1[2];
	y=y+s2[2];
	if ((x=="C"&&y=="D")||(x=="D"&&y=="C")){
		cout << "00";
		return 0;
	}
	else cout << 1;
	int n=s1[2]-'0';
	int m=s2[2]-'0';
	if (n+1==m||n-1==m) cout << 1;
	else cout << 0;
	return 0;
}
