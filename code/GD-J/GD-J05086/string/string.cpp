#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+5,M=5e3+3;
ll ans=0,tot=0;
struct Node{
	int len;
	char c;
}a[N]; 
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	string s="";
	for(int i=1;i<=n;++i){
		int num;
		char c;
		cin>>num>>c;
//		if(a[tot-1].c==c)	a[i-1].len+=num;
//		else{
//			a[tot].c=c;
//			a[tot++].len=num;
//		} 
		for(int j=1;j<=num;j++){
			s+=c;
		}
	}
	for(int i=0;i<s.size()/2;++i){
		if(s[i]!=s[s.size()-i-1])ans++;
	}
	cout<<ans;
	return 0;
}

