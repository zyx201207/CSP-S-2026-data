#include<bits/stdc++.h>
using namespace std;
int a[500005],fl[300005],ans[300005];
int pre[500005],nxt[500005],lst[300005],tt;
int dp[500005];//dp[i]：表示在nxt[i]-1前缀中有几个后缀最终包含其
struct node{
	int l,r,mx;
}t[200005];
struct nodd{
	int l,r;
}aa[500005];
void upd(int q){
	t[q].l=t[2*q].l;
	t[q].r=t[2*q+1].r;
	t[q].mx=max(t[2*q].l,t[2*q+1].r); 
}
void bd(int q,int l,int r){
	if(l==r){
		t[q].l=t[q].r=l;
		t[q].mx=aa[l].l;
		return;
	}
	int mid=(l+r)>>1;
	bd(2*q,l,mid);
	bd(2*q+1,mid+1,r);
	upd(q);
}
int fd(int q,int l,int r){
	if(t[q].l==l&&t[q].r==r){
		return t[q].mx;
	}
	if(t[2*q].r>=r) return fd(2*q,l,r);
	else if(t[2*q+1].l<=l) return fd(2*q+1,l,r);
	return max(fd(2*q,l,t[2*q].r),fd(2*q+1,t[2*q+1].l,r));
}
bool cmd(nodd A,nodd B){
	return A.r<B.r;
}
int main(){
//	freopen("card3.in","r",stdin);
	priority_queue<pair<int,int>> q;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		pre[i]=lst[a[i]];
		lst[a[i]]=i;
		if(pre[i]!=0){
			aa[++tt].l=pre[i],aa[tt].r=i;
		}
	}
	bd(1,1,tt);
	sort(aa+1,aa+tt,cmd);
	for(int i=1;i<=m;i++) lst[i]=n+1;
	for(int i=n;i>=1;i--){
		nxt[i]=lst[a[i]];
		lst[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		int l=1,r=tt,mid,ok1=-1;
		while(l<=r){
			mid=(l+r)>>1;
			if(aa[mid].r<=i){
				l=mid+1;
			}
			else{
				r=mid-1;
				ok1=mid;
			}
		}l=1,r=tt;
		int ok2=-1;
		while(l<=r){
			mid=(l+r)>>1;
			if(aa[mid].r>nxt[i]-1){
				r=mid-1;
			}
			else{
				l=mid+1;
				ok2=mid;
			}
		}
		if(ok1>0&&ok2>0){
			int mxx=fd(1,ok1,ok2);
			int ll,rr,midd,okkk=0;
			ll=ok1,rr=ok2;
			while(ll<=rr){
				midd=(ll+rr)>>1;
				if(fd(1,ok1,midd)<mxx){
					ll=midd+1;
				}
				else{
					okkk=midd;
					rr=midd-1;
				}
			}
			dp[i]=i-aa[okkk].l;
			if(pre[i]<aa[okkk].l&&pre[i]) dp[i]+=dp[pre[i]];
		}
		else{
			dp[i]=i;
		}
	}
	for(int i=n;i>=1;i--){
		if(!fl[a[i]]){
			ans[a[i]]=dp[i];
			fl[a[i]]=1;
		}
	}
	for(int i=1;i<=n;i++) cout<<dp[i]<<" ";
}
