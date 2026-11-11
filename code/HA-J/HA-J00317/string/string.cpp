#include<bits/stdc++.h>
using namespace std;
int n;
string s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	while(n--){
		int a;
		char c;
		cin>>a>>c;
		for(int i=1;i<=a;i++) s1+=c; 
	}
	string s2=s1;
	reverse(s2.begin(),s2.end());
	if(s2==s1) cout<<0;
	else{
		long long ans=0;
		for(int i=0;i<s1.size()/2;i++) if(s1[i]!=s2[i]) ans++;
		cout<<ans;
	}
	return 0;
}
