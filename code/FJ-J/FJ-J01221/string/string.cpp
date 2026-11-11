#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
int n,m,ans;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int len=0;
	for(int i=1;i<=n;i++){
		string a;
		cin>>m>>a;
		len+=m;
		for(int j=1;j<=m;j++){
			s+=a;
		}
	}
	if(len%2==0){
		for(int i=0;i<len/2;i++){
			if(s[i]!=s[len-1-i]){
				ans++;
			}
		}
	}
	else {
		for(int i=0;i<(len-1)/2;i++){
			if(s[i]!=s[len-1-i]){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
