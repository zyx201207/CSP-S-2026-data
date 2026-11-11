#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
const int maxn=2e5+5;
int n;
unsigned long long len;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		char ch;
		cin>>a>>ch;
		for(int t=1;t<=a;t++){
			s.push_back(ch);
		}
		len+=a;
	}
	long long ans1,ans2;
	if(len%2==0){
		for(int i=0;i<s.size()/2;i++){
			if(s[i]!=s[s.size()-i-1])ans1++;
		}
		for(int i=s.size()-1;i>=s.size()/2;i--){
			if(s[i]!=s[s.size()-i-1])ans2++;
		}
		cout<<max(ans1,ans2)<<'\n';
	}else{
		for(int i=0;i<s.size()/2;i++){
			if(s[i]!=s[s.size()-i-1])ans1++;
		}
		for(int i=s.size()-1;i>=s.size()/2;i--){
			if(s[i]!=s[s.size()-i-1])ans2++;
		}
		cout<<max(ans1,ans2)<<'\n';		
	}
	return 0;
}
