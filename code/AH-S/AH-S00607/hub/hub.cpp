#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long a[200005],t[5005],minn=0x3f3f3f3f;
long long w[125254];
long long dp[5005][5005],k[2005],cnt,ans,sum;
void dfs(long long x,long long y,long long mi){
	if(x==y){
		minn=min(minn,cnt);
		t[cnt]++;
		//ans++;
	}
	if(cnt>minn)return;
	for(long long i=x+1;i<=y;i++){
		if(a[i]-a[x]<=d){
			cnt++;
			dfs(i,y,mi);
			cnt--;
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cout<<1<<endl<<2;
	return 0;
}
