#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
long long n,ans;
string s,s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		while(a--){
			s+=c;
		}
	}
	s1=s;
	reverse(s1.begin(),s1.end());
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s1[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
