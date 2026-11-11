#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 300005
int a[N];
string s1,s2,c1,c2;
signed main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int len1=s1.size(),len2=s2.size();
	string num1="",num2="";
	for(int i=0; i<len1; i++)if(s1[i]<='9'&&s1[i]>='0')num1+=s1[i];
	for(int i=0; i<len2; i++)if(s2[i]<='9'&&s2[i]>='0')num2+=s2[i];
	if(c1==c2) {
		cout<<'1';
		if(num1==num2) {
				cout<<'1';
				if((s1[len1-1]<='C'&&s2[len2-1]<='C')||(s1[len1-1]>'C'&&s2[len2-1]>'C')) {
					cout<<'1';
					if(s1[len1-1]==s2[len2-1]+1||s1[len1-1]==s2[len2-1]-1) {
						cout<<'1';
					} else {
						cout<<'0';
					}
				} else {
					cout<<"00";
				}
		} else {
			cout<<"000";
		}

	} else {
		cout<<"0000";
	}



	return 0;
}
