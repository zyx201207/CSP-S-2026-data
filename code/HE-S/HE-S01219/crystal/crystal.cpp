#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=5e5+5;
int n,m,a[N],d[N];
unsigned int sum,ans,cnt,tmp;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n,cmp);
	for(int i=2;i<=n;i++){
		d[i]=a[i-1]-a[i];
	}
	queue<int> q;
	for(int i=1;i<=n;i++){
		cnt++;
		if(cnt!=1){
			sum+=tmp;
			sum+=d[i];
			tmp+=d[i];
		}
		q.push(i);
		while(sum>m&&!q.empty()){
			int x=q.front();
			q.pop();
			cnt--;
			sum-=cnt*d[x+1];
			tmp-=d[x+1];
		}
		ans=max(cnt,ans);
	}
	cout<<ans;
	return 0;
}
