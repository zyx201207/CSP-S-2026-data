#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	long long len=0;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		len+=x;
		for(int j=1;j<=x;j++){
			s+=c;
		}
	}
	bool flag=1;
	int cnt=0;
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1]){
			cnt++;
			flag=0;
		}
	}
	if(flag){
		cout<<0;
	}
	else cout<<cnt;
	return 0;
}
