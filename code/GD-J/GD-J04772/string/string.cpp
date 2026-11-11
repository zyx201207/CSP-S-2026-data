#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e5+5;
int n,a[MAXN],suml[MAXN],sumr,sumL[MAXN][30],ans;char c[MAXN];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;for(int i=1;i<=n;i++)cin>>a[i]>>c[i],suml[i]=suml[i-1]+a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=30;j++)sumL[i][j]=sumL[i-1][j];
		sumL[i][c[i]-'a'+1]++;
	}int r=n,l=1;
	while(l<r){
		if(c[l]==c[r]){int mi=min(a[l],a[r]);
			a[l]-=mi,a[r]-=mi;
			if(!a[l])l++;
			if(!a[r])r--;
			continue;
		}int mi=min(a[l],a[r]);
		ans+=mi,a[l]-=mi,a[r]-=mi;
		if(!a[l])l++;
		if(!a[r])r--;
	}cout<<ans;
	return 0;
}
/*
9
3 a
2 b
1 c
1 a
1 b
2 a
2 c
1 a
1 b

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

2
2 a
3 a

7
2 a
1 b
1 a
2 b
1 a
2 b
1 a

3
2 a
2 b
1 c
aabbc
*/
