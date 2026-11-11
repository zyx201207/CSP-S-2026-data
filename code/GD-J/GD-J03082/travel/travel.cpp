#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	long long n,m;
	n = (s1[0] - '0') * 10 + (s1[1] - '0');
	m = (s3[0] - '0') * 10 + (s3[1] - '0');
	if(n == m) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	n = (s2[0] - '0') * 10 + (s2[1] - '0');
	m = (s4[0] - '0') * 10 + (s4[1] - '0');
	if(n == m) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if((s2[2] >= 'A' && s2[2] <= 'C' && s4[2] >= 'A' && s4[2] <= 'C') || (s2[2] >= 'D' && s2[2] <= 'F' && s4[2] >= 'D' && s4[2] <= 'F')) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(s2[2] == s4[2] + 1 || s2[2] + 1 == s4[2] || (s2[2] == 'D' && s4[2] == 'F') || (s2[2] == 'F' && s4[2] == 'D'))cout<<1;
	else cout<<"0";
	return 0;
}
