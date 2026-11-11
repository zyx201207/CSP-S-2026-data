#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int answerit();
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int temp;
	cin>>temp;
	char t;
	s="*";
	for(int i=1,x;i<=temp;i++){
		cin>>x>>t;
		n+=x;
		for(int j=1;j<=x;j++) s=s+t;
	}
	cout<<answerit();
	return 0;
}
int answerit(){
	int ans=0;
	for(int i=1;i<=(n/2);i++){
		if(s[i]!=s[n-i+1]) ans++;
	}
	return ans;
}