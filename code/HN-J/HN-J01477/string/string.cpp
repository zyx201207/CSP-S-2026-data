#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],z,ans,aut;
char b[200005];
string s,s1;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n<=1){
		cout<<0;
		return 0;
	} 
    else{
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++){
				s=s+b[i];
			}
		}
		z=s.size()/2-1;
		s1=s;
		reverse(s.begin(),s.end());
		for(int i=0;i<=z;i++){
			if(s[i]!=s1[i]){
				ans++;
			}
		}
		cout<<ans;
	}
	return 0;
} 
