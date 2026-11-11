#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
const int maxn=5e5+10;
int n;
ll m,a[maxn],s[maxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);//
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int l=1,ans=1;
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		while(l<i&&a[i]*(i-l+1)-(s[i]-s[l-1])>m) l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans<<endl;
	return 0;
}
