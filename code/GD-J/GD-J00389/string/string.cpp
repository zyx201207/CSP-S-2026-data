#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=1e9+9;
string s={};
void solved(){
	int n; cin>>n;
	int x; char k;
	long long ans=0;
	for(int i=1;i<=n;i++){
		cin>>x>>k;
		for(int j=1;j<=x;j++){
			s=s+k;
		}
	}
	for(int l=0,r=s.size()-1;l<=r;l++,r--){
		if(s[l]!=s[r])
		{
			ans++;
		}
	}
	cout<<ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	int t; cin>>t;
	solved();
	return 0;
} 
