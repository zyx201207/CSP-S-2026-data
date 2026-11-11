#include<bits/stdc++.h>
using namespace std;
int a,b;
string str1,str2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>str1>>b>>str2;
	if(a!=b) cout<<"0000";
	else{
		cout<<"1";
		if(!(str1[0]==str2[0]&&str1[1]==str2[1])) cout<<"000";
		else{
			cout<<"1";
			if(!((str1[2]<='C'&&str2[2]<='C')||(str1[2]>='D'&&str2[2]>='D'))) cout<<"00";
			else{
				cout<<"1";
				if(!(abs(str1[2]-str2[2])==1)) cout<<"0";
				else cout<<"1";
			}
		}
	}
	return 0;
}
