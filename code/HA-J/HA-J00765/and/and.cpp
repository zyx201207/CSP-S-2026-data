#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1,inf=(1<<30)-1;
int a[N],cnt[4];
struct node{int l,r,val;}t[N*4];
void build(int p,int l,int r){
	t[p].l=l;t[p].r=r;
	if(l==r){
		t[p].val=a[l];
		return;
	}
	int mid=l+r>>1;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	t[p].val=t[p*2].val&t[p*2+1].val;
}
int ask(int p,int x,int y){
	int l=t[p].l,r=t[p].r;
	if(l>=x&&r<=y)return t[p].val;
	int ans=inf,mid=l+r>>1;
	if(x<=mid)ans&=ask(p*2,x,y);
	if(y>mid)ans&=ask(p*2+1,x,y);
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,mx=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],mx=max(mx,a[i]);
	sort(a+1,a+n+1);
	if(n<=20){
		int ans=0;
		for(int i=1;i<(1<<n);i++){
			int cnt=0,s=inf;
			for(int j=1;j<=n;j++)
				if(i&(1<<j-1))s&=a[j],cnt++;
			if(cnt==m)ans=max(ans,s);
		}
		cout<<ans;
		return 0;
	}
	if(n<=2000){
		if(m==1){cout<<a[n];return 0;}
		if(m==n){
			int s=inf;
			for(int i=1;i<=n;i++)s&=a[i];
			cout<<s;
			return 0;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				if(i!=j)ans=max(ans,a[i]&a[j]);
			}
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		build(1,1,n);
		int ans=0;
		for(int i=2;i<n;i++)
			ans=max(ans,ask(1,1,i-1)&ask(1,i+1,n));
		cout<<max(ans,max(ask(1,2,n),ask(1,1,n-1)));
		return 0;
	}
	if(mx<4){
		for(int i=1;i<=n;i++)cnt[a[i]]++;
		if(m<=cnt[4])cout<<4;
		else if(m<=cnt[3])cout<<3;
		else if(m<=cnt[2]+cnt[3])cout<<2;
		else if(m<=cnt[1]+cnt[3])cout<<1;
		else cout<<0;
		return 0;
	}
	int fa=1,fb=1;
	map<int,int>mp;
	for(int i=1;i<=30;i++)mp[(1<<i)-1]=1;
	for(int i=1;i<=n;i++){
		fa&=mp.count(a[i]);
		fb&=mp.count(n-1)&&(a[i]==i-1);
	}
	if(fa){cout<<a[m];return 0;}
	if(fb){
		int s=inf;
		for(int i=1;i<=m;i++)s&=a[n-i+1];
		cout<<s;
		return 0;
	}
	cout<<0;
}
