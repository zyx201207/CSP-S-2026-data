#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>n;
	while(n--){
		int a;
		char c;
		cin>>a>>c;
		while(a--)s+=c;
	}
	for(int i=0;i<=(int)s.size()/2;i++)ans+=s[i]!=s[s.size()-1-i];
	cout<<ans;
	return 0;
}
