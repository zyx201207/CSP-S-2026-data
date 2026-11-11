#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=1e6+5;
string a1,a2,b1,b2;
int ca,cb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1)cout<<1;
	else cout<<0;
	if(a2[0]==b2[0]&&a2[1]==b2[1]&&a1==b1)cout<<1;
	else cout<<0;
	if(a2[2]=='A'||a2[2]=='B'||a2[2]=='C')ca=1;
	if(b2[2]=='A'||b2[2]=='B'||b2[2]=='C')cb=1;
	if(ca==cb&&a2[0]==b2[0]&&a2[1]==b2[1]&&a1==b1)cout<<1;
	else cout<<0;
	if(abs(a2[2]-b2[2])<=1&&ca==cb&&a2[0]==b2[0]&&a2[1]==b2[1]&&a1==b1)cout<<1;
	else cout<<0;
	cout<<endl;
	return 0;
} 
