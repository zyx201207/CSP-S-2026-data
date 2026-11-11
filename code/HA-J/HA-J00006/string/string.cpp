#include <bits/stdc++.h>
using namespace std;

struct p{
	int num;
	char s;
}a[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,cnt=0;
	string s="";
	cin>>n;
	for(int i=1;i<=n;i++){
		string a="",b;
		long long m;
		cin>>m;
		cin>>b;
		for(int j=1;j<=m;j++){
			a+=b;
		}s+=a;
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i]){
			cnt++;
		}
	}cout<<cnt;
	
	return 0;
}
