#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
char s[1000000005];
int num;
int ans;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		int x;
		char c;
		cin>>x>>c;
		for(int j=1;j<=x;++j){
			num++;
			s[num]=c;
		}
	}
	if(num%2==0){
		int len=num/2;
		for(int i=1;i<=len;++i){
			if(s[i]!=s[num+1-i]){
				ans++;
			}
		}
		cout<<ans;
	}else{
		int len=num/2+1;
		for(int i=1;i<=len;++i){
			if(s[i]!=s[num+1-i]){
				ans++;
			}
		}
		cout<<ans;
	}
	/*
	3
	2 a
	2 b
	1 c
	*/
	//aabbc
	return 0;
}
