//贵阳市南明区李端棻中学 刘锦阳 GZ-J00260
#include<bits/stdc++.h>
using namespace std;
struct un{
	int a_;
	string c_;
}op[200001];
int n,num,ans,b;
string s;
int main(){
	cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++){
		int a;string c;
		cin >> a >> c;
		num += a; 
		op[i].a_ = a;
		op[i].c_ = c;
		for(int i = 1;i <= a;i++) s += c;
	}
	if(num % 2) num++;
	for(int i = 1;i <= s.size()/2;i++){
		int f = s.size();
		if(s[i] != s[f-i]){
			op[i].a_--;
			op[f-b-i].a_--;
			ans++;
		}
		if(s[i] > 0 && s[i] != s[f-b-i-1]){
			s[i]--;
			s[f-b-i-1];
			ans++;
		}
	}
	cout << ans;
	return 0;
}
