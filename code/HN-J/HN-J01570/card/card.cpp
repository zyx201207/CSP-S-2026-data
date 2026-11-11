#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+11;
ll n,m,a[N],rd[N],kd[N],t7[N],last[N];
ll zzx1[N],zzx2[N];//势力范围 zzx1   前缀和zzx2   
vector<int> fgd[N];
// xian duan shu hao shan , bai xie xian duan shu !
// % % % la_al
int mn[4*N];
void build(int k,int l,int r)
{
	if(l==r){
		mn[k]=kd[l];
		return ;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	mn[k]=max(mn[k<<1],mn[k<<1|1]);
}
int query(int k,int l,int r,int L,int R)
{
//	cout<<k<<" "<<l<<' '<<r<<" "<<L<<" "<<R<<"\n";
	if(L>R)return 0;
	if(L<=l && r<=R)
	{
		return mn[k];
	}
	int mid=l+r>>1,ans=0;
	if(L<=mid)ans=max(ans,query(k<<1,l,mid,L,R));
	if(R>mid)ans=max(ans,query(k<<1|1,mid+1,r,L,R));
	return ans;
}
int erfen(int i)
{
	//二分长度
	int l=1,r=i,ans=0;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(query(1,1,n,i-mid+1,i-1)>i)ans=mid,r=mid-1;
		else l=mid+1;
	}
	if(ans==0)return 0;
	return i-ans+1;
}
void solve()
{
	for(int i=1;i<=n;i++){
		if(rd[a[i]])last[i]=rd[a[i]];
		rd[a[i]]=i;
		fgd[a[i]].push_back(i);
	}
	for(int i=1;i<=m;i++)sort(fgd[i].begin(),fgd[i].end());
	for(int i=1;i<=n;i++)kd[i]=rd[a[i]];
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int j=rd[i];
		int t=erfen(j)+1;
		cout<<j-t+1<<" ";
	}
}
int main()
{
//	ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	solve();
	return 0;
}
/*
9:45 start

10 3
3 1 2 1 3 2 3 1 2 1

E:\HN-J01570\card\collect2.exe	[Error] ld returned 1 exit status

15 5
3 1 2 1 3 2 3 1 2 1 3 1 5 1 5
3 1 2 1 3 2 3 1 2 1
*/
