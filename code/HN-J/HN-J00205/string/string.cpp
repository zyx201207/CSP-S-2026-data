#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],cnt,ans;
string s,c[200005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];cin>>c[i];
		if(a[i]!=a[i-1]) cnt++;
	}
	if(cnt == 1){
		for(int i = 1;i <= n;i++){
		a[i]=1;
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j<=a[i];j++){
			s+=c[i];
		}
	}
	for(int i = 0;i < s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			ans++;
		} 
	}
	cout<<ans;
	return 0;
} 

