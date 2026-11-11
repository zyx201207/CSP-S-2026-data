#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
long long ans;
string s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i]>>s[i];		
	}
	int j=n;
	for (int i=1;i<=n;i++){
		if(i>=j)break;
		int cnt=min(a[i],a[j]);
		if (s[i]!=s[j])
			ans+=cnt;
		a[i]-=cnt;
		a[j]-=cnt;
		if (a[i]>0)i--;
		if (a[j]==0)j--;
	}
	cout<<ans;
	return 0;
}
