#include<bits/stdc++.h>
using namespace std;
#define int long long
char b[100000005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=0;i<n;i++){
		int m;
		char a;
		cin>>m>>a;
		while(m--)s+=a;
	}
	int cnt=0,l=s.size();
	for(int i=0;i<n;i++){
		if(s[i]!=s[l-1-i]){
			s[l-1-i]=s[i];
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
