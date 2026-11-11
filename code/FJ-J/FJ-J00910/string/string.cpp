#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
int b[30];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str,s,sp;
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s;
		for(int j=1;j<=a[i];j++){
			str+=s;
		}
	}
	int t=str.size();
		for(int i=0;i<t;i++){
			if(str[i]!=str[t-i]&&i<str.size()/2+1)ans++;
		}
    cout<<ans; 
	return 0;
}
