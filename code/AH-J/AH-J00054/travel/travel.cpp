#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s1>>s2>>s3>>s4;
	if(s1!=s3)cout<<"0000";
	else{
		cout<<"1";
		if(s2[0]!=s4[0] or s2[1]!=s4[1])cout<<"000";
		else{
			cout<<"1";
			if((s2[2]<'D' and s4[2]>'C') or (s2[2]>'C' and s4[2]<'D'))cout<<"00";
			else{
				cout<<"1";
				if((abs(int(s2[2])-int(s4[2]))==1) or (s2[2]=='D' and s4[2]=='F') or (s2[2]=='F' and s4[2]=='D'))cout<<"1";
				else cout<<"0";
			}
		}
	}
	return 0;
}
