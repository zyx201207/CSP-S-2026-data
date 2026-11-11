#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int i=1;i<=a;i++) s+=c;
	}
	int mid=(s.size()+1)/2,len=s.size();
	for(int i=0;i<=mid;i++){
		char c1=s[i],c2=s[len-i-1];
		if(c1!=c2) cnt++;
	}
	cout<<cnt;
	return 0;
}