#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int a[1010101];
char c[1010101];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int ans=0;
	string s="";
	for(int i=1;i<=n;i++){
		while(a[i]--){
			s+=c[i];
		}
	}
	int i=0,j=s.size()-1;
	while(i<j){
		if(s[i]!=s[j]){
			ans++;
		}
		i++;j--;
	}
	cout<<ans<<endl;
	return 0;
}
/*







ans:0
l:0 r:0
aabbc
aa  c














*/
