//o(n^2)²»ÐÐ!!
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n;
int a[N];
char c[N];
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	long long len=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
//	cout<<s;
	long long ans=0;
	//aaaaa len=5
	if(len%2==0){
		for(long long i=0;i<(len/2);i++)
		if(s[i]!=s[len-i-1]){
			ans++;
		}
	}
	else {
		for(long long i=0;i<((len-1)/2);i++){
			if(s[i]!=s[len-i-1]){
				ans++;
			}
		}
	}
	
//	for(long long i=0;i<(len-1)/2;i++){
//		if(s[i]!=s[len+1-i]){
//			ans++;
//		}
//	}
	cout<<ans;
	return 0;
}
