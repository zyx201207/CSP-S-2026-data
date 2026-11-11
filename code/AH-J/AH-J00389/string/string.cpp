#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	ll len;
	char c;
}a[200010];
ll n,ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].len>>a[i].c;
		for(int j=1;j<=a[i].len;j++)s+=a[i].c;
	}
	for(int i=0;i<=int(s.size())/2;i++){
		if(s[i]!=s[int(s.size())-i-1])ans++;
	}
	cout<<ans;
	return 0;
}
