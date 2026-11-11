#include <iostream>
#include <cstdio>
#define ll long long
#define H <<' '<<
using namespace std;
char a3,b3;
string s;
ll a1,a2,b1,b2;
// AB BA BC CB DF FD AC CA
// AB BA BC CB DF FD
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>a3>>b1>>b2>>b3;
	s="  ";s[0]=a3;s[1]=b3;
	cout<<(a1==b1);
	cout<<(a1==b1&&a2==b2);
	cout<<(a1==b1&&a2==b2&&(s=="AB"||s=="BA"||s=="BC"||s=="CB"||s=="DF"||s=="FD"||s=="AC"||s=="CA"));
	cout<<(a1==b1&&a2==b2&&(s=="AB"||s=="BA"||s=="BC"||s=="CB"||s=="DF"||s=="FD"));
	return 0;
}
// 100
