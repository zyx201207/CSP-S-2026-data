#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
struct node{
	//val:原值 num:二进制形式下多少个1
	int val,num;
}a[N];
int n,m,ans,wei[N];
int turn(int x){
	int cnt=0,i=1;
	memset(wei,0,sizeof wei);
	while(x){
		int tmp=x%2;
		x>>=1;
		wei[i++]=tmp;
		if(tmp)cnt++;
	}
	return cnt;
}
bool cmp(node p,node q){
	if(p.num==q.num)return p.val>q.val;
	return p.num>q.num;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].val;
		a[i].num=turn(a[i].val);
	}
	sort(a+1,a+n+1,cmp);
	ans=a[1].val;
	for(int i=2;i<=m;i++)
		ans&=a[i].val;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
