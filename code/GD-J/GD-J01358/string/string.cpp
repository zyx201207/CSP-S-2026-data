#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+7;
int n,a[N],len;
char ch[N];
string s;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ch[i];
		len+=a[i];int t=1;
		while(t<=a[i]) t++,s+=ch[i];
	}
	if(n==1){
		cout<<0;
	}else if(n==2){
		if(ch[1]==ch[2]) cout<<0;
		else cout<<min(a[1],a[2]);
	}else{
		s=" "+s;
		int mid=(len+1)/2,ans=0;
		for(int i=1;i<=mid;i++){
			if(s[i]!=s[len-i+1]) ans++;
		}cout<<ans;
	}
	return 0;
}
/*
4
10 a
5 b
5 c
10 a
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
