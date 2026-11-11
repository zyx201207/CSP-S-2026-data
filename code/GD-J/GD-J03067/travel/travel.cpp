#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define endl '\n'
using namespace std;
int c1,c2,n1,n2,m1,m2;
string s1,s2;
int get_m(char c){
	if(c=='A') return 1;
	if(c=='B') return 2;
	if(c=='C') return 3;
	if(c=='D') return 4;
	if(c=='F') return 5;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	n1=(s1[0]-'0')*10+(s1[1]-'0');
	n2=(s2[0]-'0')*10+(s2[1]-'0');
	m1=get_m(s1[2]);
	m2=get_m(s2[2]);
	if(c1!=c2) cout<<"0000";
	else if(n1!=n2) cout<<"1000";
	else if(!(m1+m2==4+5||m1<4&&m2<4)) cout<<"1100";
	else if(!(abs(m1-m2)==1)) cout<<"1110";
	else cout<<"1111";
	return 0;
}
