//1~12,17,18
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll n,a,sum,cnt;
string s;
char c;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		sum+=a;
		for(int j=1;j<=a;j++) s+=c;
	}
	if(sum%2==1){
		for(int i=0;i<(sum/2);i++){
			if(s[i]!=s[sum-i-1]) cnt++;
		}
	}else{
		for(int i=0;i<(sum/2);i++){
			if(s[i]!=s[sum-i-1]) cnt++;
		}
	}
	cout<<cnt;
	
	
	return 0;
}
/*
4
2 a
1 b
2 c
2 d
aabcc
*/
