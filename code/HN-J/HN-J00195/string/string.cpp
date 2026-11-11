#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
int is(int n){
	int maxn=1;
	for(int i=1;i*i<=n;i++){
		if(n%i==0)maxn=i;
	}
	return maxn;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,ans=0;
	string s="";
	cin>>n;
	while(n--){
		int a;
		char c;
		cin>>a>>c;
		string p="";
		int pr=is(a);
		while(pr--)p=p+c;
		a=a/is(a);
		while(a--)s=s+p;
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i])ans++;
	}cout<<ans;
	return 0;
}
