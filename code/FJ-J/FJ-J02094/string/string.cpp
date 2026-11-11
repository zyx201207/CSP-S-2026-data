#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	while(n--){
		int a;
		string ch;
		cin>>a>>ch;
		while(a--)
			s+=ch;
	}
	long long ans=0;
	for(int i=0;i<=s.size()/2-1;i++)
		if(s[i]!=s[s.size()-i-1])
			ans++;
	cout<<ans<<endl;
	return 0;
}
