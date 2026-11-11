#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d;
	string s,z;
	cin >> a >> b >> s >> c >> d >> z;
	if(a==c){
		cout << 1;
		if(b==d){
			cout << 1;
			if((s=="A" && z=="D") || (s=="B" && z=="D") || (s=="C" && z=="D") || (s=="A" && z=="F") || (s=="B" && z=="F") || (s=="C" && z=="F"))
				cout << "00";
			else{
				cout << 1;
				if(s=="A" && z=="B" || s=="B" && z=="C" || s=="D" && z=="F") cout << 1;
				else cout << 0;
			}
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
} 
