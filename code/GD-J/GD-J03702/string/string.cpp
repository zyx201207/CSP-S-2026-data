#include<bits/stdc++.h>
using namespace std;
struct node{
	int p;
	char c;
}a[200005];
int n,tot=0;
string s="";
bool chk(){
	for(int i=0;i<s.size();i++){
		if(s[i]!=s[s.size()-i-1])return 0;
	}
	return 1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;char y;
		cin>>x>>y;
		for(int j=1;j<=x;j++)s+=y;
	}
	int ans1=0,ans2=0;
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			ans1++;
		}
	}
	cout<<ans1;
}

