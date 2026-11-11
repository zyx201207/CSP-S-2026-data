#include <bits/stdc++.h>
using namespace std;
int n1,n2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n1>>s1>>n2>>s2;
	if(n1!=n2)
		cout<<"0000";
	else{
		cout<<"1";
		if(s1[0]!=s2[0] || s1[1]!=s2[1])
			cout<<"000";
		else{
			cout<<"1";
			if((s1[2]<='C'&&s2[2]>='D') || (s1[2]>='D'&&s2[2]<='C'))
				cout<<"00";
			else{
				cout<<"1";
				cout<<(abs(s1[2]-s2[2])<=1 ? "1" : "0");
			}
		}
	}
	return 0;
}
