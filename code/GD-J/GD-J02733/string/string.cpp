#include<bits/stdc++.h>

using namespace std;


int t;

bool check(string s){
	int l=0,r=s.length()-1;
	while (l<=r){
		if (s[l]!=s[r])return 0;
		l++,r--;
	}
	return 1;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	int n=0;
	string s="";
	while (t--){
		int m;
		char c;
		cin>>m>>c;
		n+=m;
		for (int i=1;i<=m;i++)s+=c; 
	}
	if (check(s)){
		cout<<0;
		return 0;
	}
	int cnt=0;
	for (int i=n-1;i>=0;i--){
		if (check(s)){
			cout<<cnt;
			break;
		}
		cnt++; 
		s[i]=s[0];
	}
	return 0;
} 
