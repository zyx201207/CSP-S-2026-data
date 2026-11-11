#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	int n1,n2;
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if (c1==c2)
		cout<<"1";
	else
		cout<<"0";
	if (c1==c2 and s1[0]==s2[0] and s1[1]==s2[1])
		cout<<"1";
	else
		cout<<"0";
	if (c1==c2 and s1[0]==s2[0] and s1[1]==s2[1]){
		n1=s1[2];
		n2=s2[2];
		if ((n1<=67 and n2<=67) or (n1>=68 and n2>=68))
			cout<<"1";
		else
			cout<<"0";
	}
	else
		cout<<"0";
	
	if (c1==c2 and s1[0]==s2[0] and s1[1]==s2[1]){
		n1=s1[2];
		n2=s2[2];
		if ((n1<=67 and n2<=67) or (n1>=68 and n2>=68)){
			if (abs(n1-n2)==1 and ((n1!=67 and n2!=68) or (n2!=67 and n1!=68)))
				cout<<"1";
			else
				cout<<"0";
		}
		else
			cout<<"0";
	}
	else
		cout<<"0";
	return 0;
}
