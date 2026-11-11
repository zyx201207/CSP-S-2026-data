#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		while(x--){
			s+=c;
		}
	}
	int cnt=0;
	for(int i=0;i*2<s.size();i++){
		if(s[i]!=s[s.size()-i-1]){
			cnt++;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
	//68
}
