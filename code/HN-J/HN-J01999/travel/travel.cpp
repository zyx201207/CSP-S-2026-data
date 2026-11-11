#include<bits/stdc++.h>
#define int long long
//#define pii pair<int,int>
using namespace std;
string a1,s1,a2,s2; 
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>a1>>s1>>a2>>s2;
	int q=1;
	if(a1!=a2)q*=0;
	cout<<q;
	if(!(s1[0]==s2[0]&&s1[1]==s2[1]))q*=0;
	cout<<q;
	if(!((('A'<=s1[2]&&s1[2]<='C')&&('A'<=s2[2]&&s2[2]<='C'))||(('D'<=s1[2]&&s1[2]<='E')&&('D'<=s2[2]&&s2[2]<='E'))))q*=0;
	cout<<q;
	if(abs(s1[2]-s2[2])!=1)q*=0;
	cout<<q;
	return 0;
} 
