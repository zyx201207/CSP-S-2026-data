#include<bits/stdc++.h>
#define int long long
using namespace std;
int t;
string s;
int cnt;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	int n=0;
	while(t--){
		int x;
		char c;
		cin>>x>>c;
		for(int i=1;i<=x;i++){
			s[++n]=c;		
		}
	}
	int k=n/2;
	for(int i=1,j=n;i<=k&&j>=k;i++,j--){
		if(s[i]!=s[j]){
			cnt++;
		}
	}
	cout<<cnt;
    return 0;
}
