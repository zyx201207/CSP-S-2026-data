#include<bits/stdc++.h>
using namespace std;

int calc(char ch) {
	if(ch=='A'||ch=='B'||ch=='C') return 0;
	else return 1;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else cout<<0;
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]) cout<<1;
	else cout<<0;
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&calc(s1[2])==calc(s2[2])) cout<<1;
	else cout<<0;
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&calc(s1[2])==calc(s2[2])&&abs(s1[2]-s2[2])==1) cout<<1;
	else cout<<0;
	cout<<"\n";
	return 0;
}

