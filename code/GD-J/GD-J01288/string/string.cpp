#include<bits/stdc++.h>
using namespace std;
#define int long long
//70%
vector<char>v;
int n,a;
char c;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.ans","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++)v.push_back(c);
	}
	int ans=0;
	for(int i=0;i<v.size()/2;i++){
		if(v[i]!=v[v.size()-i-1])ans++;
	}
	cout<<ans;
	return 0;
}


















