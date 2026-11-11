#include<bits/stdc++.h>

using namespace std;

int n,cnt;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	string s1="";
	for(int i=1;i<=n;++i){
		int num;
		char val;
		cin >> num;
		cin >> val;
		for(int i=1;i<=num;++i) s1+=val;
	}
	int ans=0;
	int len = s1.size();
	for(int i=0;i<len/2;++i){
		if(s1[i]!=s1[len-i-1]) ans++;
	}
	cout << ans;
	return 0;
}
