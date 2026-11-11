#include<bits/stdc++.h>
#define int long long
//#define pii pair<int,int>
using namespace std;
int n,a[1000000],l;
char b[1000000];
string s=" ";
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		l+=a[i];
		for(int j=1;j<=a[i];j++){
			s+=b[i];
		}
	}
	//cout<<l;
	int ans=0;
	for(int i=1;i<=l/2;i++){
		if(s[i]!=s[l+1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
