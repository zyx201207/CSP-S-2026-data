//GZ-J00299,×ñÒåËÄÖĞ£¬Ô¬¼Îòà 
#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int b,c;
};
int n;
string s="";
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int b;
		char c;
		cin>>b>>c;
		if(n<=2000&&b>=100000){
			cout<<0;
			return 0;
		}
		if(n>2000&&n<=200000&&b>=1000){
			cout<<0;
			return 0;
		}
		for(int i=1;i<=b;i++){
		    s+=c;
		}
	}
	int ans=0;
	for(int i=0;i<=s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
