#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
using namespace std;
int n;
int len;
int ans;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		for(int j=1;j<=x;j++){
			s+=c;
			len++;
		}
	}
	s="#"+s;
	int L=0,R=0;
	if(len%2==0){
		L=len/2,R=len/2+1;
	}else{
		L=len/2,R=len/2+2;
	}
	while(1){
		if(L<1||R>len){
			break;
		}
		if(s[L]!=s[R]){
			ans++;
		}
		L--;
		R++;
	}
	cout<<ans;
	return 0;
}
