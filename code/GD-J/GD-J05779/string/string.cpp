#include<bits/stdc++.h>
using namespace std;
#define int long long
map<char,int>mp;
int n,a,kind=0;
char c;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		if(mp[c]==0)kind++;
		mp[c]+=a;
	}
	if(kind==1){
		cout<<0;
		return 0;
	}
	int mi=200005;
	for(char i='a';i<='z';i++){
		if(mp[i]!=0)mi=min(mi,mp[i]);
	}
	cout<<mi;
}
