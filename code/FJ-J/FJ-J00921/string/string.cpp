#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	string s="";
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++) s+=c;
	}
	long long k=floor(s.size()/2),num=0;
	for(int i=0;i<k;i++){
		if(s[i]!=s[s.size()-i-1]) num++;
	}
	cout << num;
	return 0;
}
