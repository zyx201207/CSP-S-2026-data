#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string cc;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int m;
		cin>>m;
		cin>>cc;
		for(int j=1;j<=m;j++){
			s+=cc;
		}
	}
	int o=0;
	int h=s.size();
	for(int i=0;i<h/2;i++){
		if(s[i]!=s[h-i-1]) o++;
	}
	cout<<o;
	return 0;
}
