#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
ll n,ans=0;
ll a;
string s="";
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++)s+=c;
	}
	for(int i=0,j=s.size()-1;i<=j;i++,j--)
		if(s[i]!=s[j])ans++;
	cout<<ans;
	return 0;
}
//70%ÑùÀý 
