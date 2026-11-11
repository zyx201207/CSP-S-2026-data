#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define ull unsigned long long
#define endl '\n'
#define INF 0x3f3f3f3f
#define lowbit(x) (x&(-x))
#define pll pair<int,int>
const int N=5e5+5,M=3e5+5;
int last,n,m,a[N];
int f[N];
int res[N];
int num[N];
int sum[N];
int tr[M<<2];
void pushup(int i,int l,int r){
	if(l==r)return;
	tr[i]=max(tr[i*2],tr[i*2+1]);
}
void modify(int i,int l,int r,int k,int val){
	if(l==r){
		tr[i]=max(tr[i],val);
		return;
	}
	int mid=(l+r)>>1;
	if(k<=mid)modify(i*2,l,mid,k,val);
	else modify(i*2+1,mid+1,r,k,val);
	pushup(i,l,r);
}
int query(int i,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr)return tr[i];
	int mid=(l+r)>>1,ans=0;
	if(ql<=mid)ans=max(query(i*2,l,mid,ql,qr),ans);
	if(qr>mid)ans=max(query(i*2+1,mid+1,r,ql,qr),ans);
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)sum[a[i]]++;
	last=a[n];
	for(int i=1;i<=n;i++)num[a[i]]=i;
	if(sum[a[1]]>1)modify(1,1,n,num[a[1]],1);
	for(int i=2;i<=n;i++){
		f[i]=query(1,1,n,i,n);
//		cout<<i<<":"<<f[i]<<" "<<num[a[i-1]]<<endl;
//		cout<<i<<":"<<f[i]<<endl;
		if(sum[a[i]]>1)modify(1,1,n,num[a[i]],i);
	}
//	cout<<query(1,1,n,1,3);
//	for(int i=1;i<=n;i++)cout<<f[i]<<endl;
	for(int i=1;i<n;i++)res[a[i]]+=i-f[i];
	for(int i=1;i<=m;i++){
		if(i==last)cout<<n<<" ";
		else cout<<res[i]<<" ";
	}
	return 0;
}

