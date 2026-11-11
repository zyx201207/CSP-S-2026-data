#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n;
int a[N];
char s[N];
int sum;
string ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			ans+=s[i];
		}
	}
	for(int i=0;i<ans.size();i++){
		if(s[i]!=s[ans.size()-i-1]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
} 
