#include<iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
    string s="";
    int n;cin>>n;
    for(int i=1;i<=n;i++){
    	int num;char c;
    	cin>>num>>c;
    	for(int j=1;j<=num;j++)s.push_back(c);
	}
	string s2=s;
	reverse(s2.begin(),s2.end());
	if(s2==s)return cout<<0,0;
	int dot=s.size()/2;
	int ans=0;
	for(int i=dot;i>=0;i--){
		if(n-i-1>=0&&n-i-1>=n)continue;
		if(s[i]!=s[n-i-1])ans++;
	}
	cout<<ans;
	return 0;
} 

