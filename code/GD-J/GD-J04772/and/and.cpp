#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e5+5;
int n,m,a[MAXN],ans=(1ll<<32)-1,sy;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m,sy=n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=31;i>=0;i--){
		int t=0;
		for(int j=1;j<=n;j++)
			if(a[j]!=-1)
				if((a[j]>>i)&1)
					t++;
		if(t<m)continue;
		for(int j=1;j<=n;j++)
			if(a[j]!=-1)
				if(!((a[j]>>i)&1)){
					if(sy==m)break;
					a[j]=-1,sy--;
				}
	}for(int i=1;i<=n;i++)
		if(a[i]!=-1)
			ans&=a[i];
	cout<<ans;
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
