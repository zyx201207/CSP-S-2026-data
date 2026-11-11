#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s="";
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		string sx;
		cin>>x>>sx;
		while(x--) s+=sx;
	}
	string sa=s;
	reverse(sa.begin(),sa.end());
	long long cnt=0;
	for(int i=0;i<s.size();i++){
		if(sa[i]!=s[i]) cnt++;
	}
	cout<<cnt/2;
	return 0;
} 
