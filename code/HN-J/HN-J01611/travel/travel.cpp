#include<bits/stdc++.h>
using namespace std;
#define int long long
int pd,pd1,pd2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	string s,s1,n,n1;
	cin>>s>>s1>>n>>n1;
	if(s == n){
		pd = 1;
		cout<<1;
	} 
	else{
		cout<<0;
	}
	int a = (s1[0] - '0') * 10 + s1[1] - '0';
	int b = (n1[0] - '0') * 10 + n1[1] - '0';
	if(pd == 1 && a == b){
		cout<<1;
		pd1 = 1;
	}
	else cout<<0;
	char x = s1[2],y = n1[2];
	if((pd == 1 && pd1 == 1) && (((x >= 'A' && x <= 'C') && (y >= 'A' && y <= 'C')) || ((x == 'D' && y == 'F') || (x == 'F' && y == 'D')))){
		cout<<1;
		pd2 = 1;
	}
	else{
		cout<<0;
	}
	if(pd2 == 1 && ((x == 'A' && y == 'B') || (x == 'B' && y == 'A') || (x == 'B' && y == 'C') || (x == 'C' && y == 'B') || (x == 'D' && y == 'F') || (x == 'F' && y == 'D'))){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
