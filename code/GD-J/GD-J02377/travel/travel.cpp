#include <bits/stdc++.h>
using namespace std;

bool smsd[5] = {0,0,0,1,1};

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if (s1 == s3) cout<<1;
	else cout<<0;
	
	bool flag1 = 0;
	for (int i=0;i<=1;i++) {
		if (s2[i] != s4[i]) flag1 = 1;
	}
	if (flag1 || s1 != s3) cout<<0;
	else cout<<1;
	
	if (smsd[s2[2] - 'A'] == smsd[s4[2] - 'A'] && !flag1 && s1 == s3) cout<<1;
	else cout<<0;
	
	if (smsd[s2[2] - 'A'] == smsd[s4[2] - 'A'] && abs(s2[2] - s4[2]) <= 1 && !flag1 && s1 == s3) cout<<1;
	else cout<<0;
}
