#include <bits/stdc++.h>
using namespace std;
int n,m;
long long ans=-1;
long long a[200005];
string two(long long w){
	string s;
	while(w>0){
		int y=w%2; 
		s+=char(y+'0');
		w/=2;
	}
	return s;
}
long long yu(string p,string q){
	long long ans=0;
	long long j=1;
	for(int i=0;i<=min(p.size(),q.size())-1;i++){
		if(p[i]=='1'&&q[i]=='1') ans+=j;
		j*=2; 
	}
	return ans;
}
bool cmp(long long x,long long y){
	string s1=two(x),s2=two(y);
	int cnt1=0,cnt2=0;
	for(int i=0;i<=max(s1.size(),s2.size())-1;i++){
		if(i<=s1.size()-1&&s1[i]=='1') cnt1++;
		if(i<=s2.size()-1&&s2[i]=='1') cnt2++;
	}
	if(cnt1>=cnt2) return x;
	return y; 
}
void dfs(int o,long long last,int l){
	if(o==m){
		ans=max(last,ans);
		return;
	}
	for(int i=l;i<=n;i++){
		dfs(o+1,yu(two(a[i]),two(last)),i+1);
	}
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,1073741823,1);
	cout<<ans;
	return 0;
}

