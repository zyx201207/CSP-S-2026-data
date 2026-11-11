#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n,len;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		ll m;
		char c;
		cin>>m>>c;
		len+=m;
		for(int i=1;i<=m;i++){
			s+=c;
		}
	}
	ll ans=0;
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
//预计过 1~12,17~21 测试点 
//预计分数60 

