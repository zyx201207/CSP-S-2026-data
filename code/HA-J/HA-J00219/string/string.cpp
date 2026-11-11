#include <bits/stdc++.h>
using namespace std;
int n,v=0,gai=0;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char d;
		cin>>x>>d;
		for(int i=1;i<=x;i++)s+=d;
	}
	if(s.size()%2==1)v=1;
	for(int i=0;i<s.size()/2;i++){
		if(s[s.size()-i-1]!=s[i]){
			gai++;
		}
	}
	cout<<gai<<endl;
	return 0;
}
