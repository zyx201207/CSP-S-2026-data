#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0,maxn=0,sum=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	vector<int> a(n+1);
	vector<string> s(n+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		int x=a[i];
		while(x) s[i].push_back(x%2+48),x/=2;
		reverse(s[i].begin(),s[i].end());
		if(s[i].size()==0) s[i].push_back('0');
	}
	sort(s.begin()+1,s.end(),greater<string>());
	ans=stoi(s[1],nullptr,2);
	if(ans==0) if(m+1<=n) ans=(1<<31)-1,m++;
	for(int i=2;i<=m;i++){
		int ans1=ans;
		ans=ans&stoi(s[i],nullptr,2);
		if(ans==0) if(m+1<=n) ans=ans1,m++;
	}
	if(n!=1) cout<<ans;
	else cout<<s[1];
} 
