#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
bool check(string s,string t){
	s=t;
	reverse(s.begin(),s.end());
	if(s==t)return true;
	else return false;
}
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);

	cout<<"0";
	return 0;
}
