#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//const int ma=;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	string a,b,x,y;
	cin>>a>>b>>x>>y;
	string s1=b.substr(0,2),s2=y.substr(0,2);
	cout<<(int)(a==x);
	cout<<(int)(a==x&&s1==s2);
	cout<<(int)(a==x&&s1==s2&&((b[2]<='C'&&y[2]<='C')||(b[2]>='D'&&y[2]>='D')));
	cout<<(int)(a==x&&s1==s2&&((b[2]<='C'&&y[2]<='C')||(b[2]>='D'&&y[2]>='D'))&&((abs(b[2]-y[2])==1)||(b[2]=='D'&&y[2]=='F')||(b[2]=='F'&&y[2]=='D')));
	return 0;
}
/*
*/
