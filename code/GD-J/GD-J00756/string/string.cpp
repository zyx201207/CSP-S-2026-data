#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005],ans;
char c[200005];
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie();
	cout.tie();
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=a[i];j++)s+=c[i];
	for(int i=0,j=s.size()-1;i<=j;i++,j--){
		if(s[i]!=s[j])ans++;
	}
	cout<<ans;
	return 0;
}
