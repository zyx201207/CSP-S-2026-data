#include <bits/stdc++.h>
using namespace std;
int main() {
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	long long a;
	char c;
	string S="";
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++) S+=c;
	}
	int len=S.size();
	if(n==1) cout<<0;
	for(int i=0;i<len/2;i++){
		if(S[i]!=S[len-i]) cnt++;
	}
	
	cout<<cnt;
	return 0;
}


