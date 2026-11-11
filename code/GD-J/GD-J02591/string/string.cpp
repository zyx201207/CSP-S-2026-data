#include<bits/stdc++.h>
using namespace std;
#define int long long
using p=pair<int,int>;
constexpr int N=200009;
int s[N];
int e[N];
int a[N];
int pre[N][26];
void solve(){
	int n;
	cin>>n;
	int last=1;
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		s[i]=last;
		last+=x;
		e[i]=last-1;
		a[i]=y-'a';
	}
	int lent=last-1;
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<26;j++){
			pre[i][j]=pre[i-1][j];
		}
		pre[i][a[i]]+=e[i]-s[i]+1;
	}
	for(int i=1;i<=n;i++){
		if(s[i]>lent/2){
			break;
		}
		int r=lent-s[i]+1;
		int l=max((lent+1)/2+1,lent-e[i]+1);
		int cnt=0;
		int f1=upper_bound(s+1,s+1+n,l)-s-1;
		int f2=lower_bound(e+1,e+1+n,r)-e;
		cnt+=pre[f2][a[i]]-pre[f1-1][a[i]];
		if(a[f1]==a[i]){
			cnt-=l-s[f1];
		}
		if(a[f2]==a[i]){
			cnt-=e[f2]-r;
		}
		ans+=r-l+1-cnt;
	}
	cout<<ans;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int _=1;
	//cin>>_;
	while(_--)
		solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
