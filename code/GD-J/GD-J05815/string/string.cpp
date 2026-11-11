#include<bits/stdc++.h>
using namespace std;
pair<long long,char>p[200003];
long long n,a,ans;
char b;
bool f(long long l,long long r){
	if(p[l].first==0)return 1;
	return 0;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		p[i]={a,b};
	}
	int l=1,r=n;
	while(l<r){
		long long x=min(p[l].first,p[r].first);
		p[l].first-=x;p[r].first-=x;
		if(p[l].second!=p[r].second)ans+=x;
		if(f(l,r))l++;
		else r--;
	}
	cout<<ans;
}
