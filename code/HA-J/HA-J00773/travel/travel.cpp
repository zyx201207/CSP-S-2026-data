#include<bits/stdc++.h>
using namespace std;

string c1,c2,s1,s2;
int ans = 1;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	cout<<(c1 == c2 ? 1 : 0);
	ans &= (c1 == c2 ? 1 : 0);
	cout<<((s1.substr(0,2) == s2.substr(0,2) ? 1 : 0)&ans);
	ans &= (s1.substr(0,2) == s2.substr(0,2) ? 1 : 0);
	cout<<(((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] > 'C' && s2[2] > 'C') ? 1 : 0)&ans);
	ans &= ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] > 'C' && s2[2] > 'C') ? 1 : 0);
	cout<<((abs(s1[2]-s2[2]) == 1 || (abs(s1[2]-s2[2]) == 2 && (s1[2] == 'F' || s2[2] == 'F')) ? 1 : 0)&ans);
	return 0;
}
