#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,sum=0;
int a[200005],pw[35],b[200005];
bool cmp(int x,int y){
	return x > y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	pw[0]=1;
	for(int i = 1;i <= 30;i++){
		pw[i]=pw[i-1]*2;
	}
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(int i = 0;i <= 30;i++){
		int cnt=0;
		for(int j = 1;j <= n;j++){
			if(a[j]>=pw[i]){
				b[++cnt]=a[j];
			}
		}
		sort(b+1,b+cnt+1,cmp);
		if(cnt<m){
			break;
		}
		int ans=b[1];
		for(int j = 2;j <= m;j++){
			ans&=b[j];
		}
		sum=max(sum,ans);
	}
	cout<<sum;
	return 0;
}
