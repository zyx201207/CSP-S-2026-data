#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,cnt;
int a[N];
char c[N];
string s;
bool hw(string x){
	string t=x;
	reverse(x.begin(),x.end());
	return x==t;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
//	cout<<s<<"\n";
	if(hw(s)){
		cout<<0;
		return 0;
	}
	int len=s.size();
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1]){
//			cout<<i<<" "<<len-i-1<<"\n";
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
