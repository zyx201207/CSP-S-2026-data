#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[200100];
string intwo(int x){
	string s = "";
	int chu,yu;
	char t;
	chu = x;
	while (chu != 0){
		yu = chu % 2;
		chu = chu / 2;
		t = yu + '0';
		s = t + s;	
	}
	return s;	
}
string an(string x,string y){
	string s;
	for (int i = 0;i < x.size();i ++){
		if (x[i] == y[i] && x[i] == '1') s = s + "1";
		else s = s + "0";
	}
	return s;
}
int inten(string x){
	char t;
	int q = 1;
	int ans = 0;
	for (int i = x.size() - 1;i >= 0;i --){
		t = x[i];
		int w = t - '0';
		ans = ans + q * w;
		q = q * 2;
	}
	return ans;
}
int main(){
	freopen("and.in","c",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i = 1;i <= n;i ++) cin>>a[i];
	return 0;
}

