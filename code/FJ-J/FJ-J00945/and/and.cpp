#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;
int n,m,a[N],sum,ans;

struct dian{
	int w,cnt;
}b[N];

void dfs(int cn,int num,int las){
	//cout<<cn<<' '<<num<<' '<<las<<'\n';
	if(cn>=m){
		ans=max(ans,num);
		return;
	}
	for(int i=las;i<=sum;i++)
		dfs(cn+b[i].cnt,num&b[i].w,i+1);
}

bool cmp(int x,int y){
	return x>y;
}

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]){
			b[++sum].w=a[i];
			b[sum].cnt=1;
		}
		else
			b[sum].cnt++;
	}
	for(int i=1;i<=sum;i++)
		dfs(b[i].cnt,b[i].w,i+1);
	cout<<ans;
	return 0;
}
