#include<bits/stdc++.h>
using namespace std;
#define ll long long

string c1,s1,c2,s2;
bool b[4];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if (c1 == c2){
		b[0] = 1;
		if (s1[0] == s2[0] && s1[1] == s2[1]) b[1] = 1;
		if (b[1] == 1 && ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D'))) b[2] = 1;
		if (abs(s1[2]-s2[2]) == 1 && b[2] == 1) b[3] = 1;
	}
	for (int i=0;i<4;i++){
		cout<<b[i];
	}
	return 0;
}

