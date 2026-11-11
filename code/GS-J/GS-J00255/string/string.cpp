#include<bits/stdc++.h>
using namespace std;
string s;
long long n;
bool ok(string s){
	string tmp=s;
	reverse(tmp.begin(),tmp.end());
	return s==tmp;
}
int dfs(long long step,string s){
	if(ok(s)){
		return step;
	}
	step++;
	for(long long i=0;i<s.size();i++){
		long long next=s.size()-1-i;
		char c=s[next]; // record
		if(s[i]!=s[next]){
			// 1:change second
			s[next]=s[i];
			long long step1=dfs(step,s);
			s[next]=c; // back
			c=s[i]; // record
			// 2:change second
			s[i]=s[next];
			long long step2=dfs(step,s);
			s[i]=c; // back
			step=min(step1,step2); // change
		}
	}
	return step;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		for(long long j=1;j<=a;j++){
			s.push_back(c);
		}
	}
	long long ans=dfs(0LL,s);
	cout<<ans<<'\n';
	return 0;
}
