#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N=1e6+5;
const int mod=1e9+7;
const int inf=2e9;
int c1,c2;
string s1,s2;
struct aa{
	int p,d;
}r,x;
void js(aa &a,string s){
	a.p=(int)(s[0]-'0')*10+(int)(s[1]-'0');
	a.d=(int)(s[2]-'A'+1);
}
bool pd(int a,int b){
	return (a<=3 && b<=3) || (a>3 && b>3);
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	js(r,s1); js(x,s2);
	if(c1!=c2){
		cout << "0000";
		return 0;
	}
	else{
		cout << 1;
	}
	if(r.p!=x.p){
		cout << "000";
		return 0;
	}
	else{
		cout << 1;
	}
	if(!pd(r.d,x.d)){
		cout << "00";
		return 0;
	}
	else{
		cout << 1;
	}
	if((r.d+1==x.d) || (x.d+1==r.d)){
		cout << 1; 
	}
	else{
		cout << 0;
	}
	return 0;
}


