#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int a[6]{1,2,3,4,0,5};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s1>>s2>>s3>>s4;
	if(s1!=s3)cout<<"0000";
	else{
		cout<<"1";
		if(s2[0]!=s4[0]||s2[1]!=s4[1])cout<<"000";
		else{
			cout<<"1";
			if(s2[2]>='D'&&s4[2]<='C'||s2[2]<='C'&&s4[2]>='D')cout<<"00";
			else{
				cout<<"1";
				if(abs(a[s2[2]-'A']-a[s4[2]-'A'])==1)cout<<"1";
				else cout<<"0";
			}
		}
	}
	return 0;
}
