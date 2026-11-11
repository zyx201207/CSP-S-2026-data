#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+10;
int n,m;
int a[maxn];
int b[maxn];
int ans[maxn];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]=i;
	}
	int l=0;
	for(int i=1;i<=n;i++){
		int c=a[i];
		int c2=a[i-1];
		if(b[c2]==i-1){
			ans[c]+=ans[c2];
		}
		ans[c]+=i-l;
		l=i;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

