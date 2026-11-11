#include<bits/stdc++.h>
using namespace std;
int a[]={1,1,1,2,2};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long c1,c2;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2){
		cout << "1";
		c1=(s1[0]-'0')*10+(s1[1]-'0');
		c2=(s2[0]-'0')*10+(s2[1]-'0');
		if(c1==c2){
			cout << "1";
			if(a[s1[2]-'A']==a[s2[2]-'A']){
				cout << "1";
				if(abs(s1[2]-s2[2])==1) cout << "1";
				else cout << "0";
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
