#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N];
char c[N];
int tong[26];
int d=0;
long long ans=0;
string s=" ";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		tong[c[i]-'a']++;
	}
	for(int i=0;i<26;i++){
		if(tong[i]) d++;
	}
	if(d==1){
		cout<<0;
		return 0;
	}
	long long cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
			cnt++;
		}
	}//TLE
	for(int i=1;i<=cnt/2;i++){
		if(s[i]==s[cnt-i+1]) continue;
		ans++;
	}
	cout<<ans;
	return 0;
}
