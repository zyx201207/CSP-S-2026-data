#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int lst[500005];
int nxt[500005];
int ans[500005];
//segment_tree
int tr[500005*4];
int tag[500005*4];
void modify(int u,int l,int r,int ql,int qr,int k){//add
	if(ql<=l&&qr>=r){
		tr[u]+=(r-l+1)*k;
		tag[u]+=k;
		return ;
	}
	int mid=(l+r)/2;
	if(ql<=mid) modify(u<<1,l,mid,ql,qr,k);
	if(qr>mid) modify(u<<1|1,mid+1,r,ql,qr,k);
	tr[u]=tr[u<<1]+tr[u<<1|1];
}
int query(int u,int l,int r,int pos){
	if(r<pos||l>pos) return 0;
	if(l==r){
		return tr[u];
	}
	int mid=(l+r)/2;
	tag[u<<1]+=tag[u];
	tr[u<<1]+=(mid-l+1)*tag[u];
	tag[u<<1|1]+=tag[u];
	tr[u<<1|1]+=(r-mid)*tag[u]; 
	tag[u]=0;
	if(pos<=mid) query(u<<1,l,mid,pos);
	else return query(u<<1|1,mid+1,r,pos);
}
//end
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	memset(lst,-1,sizeof(lst));
	memset(nxt,-1,sizeof(nxt));
	for(int i=1;i<=n;i++){
		if(lst[a[i]]!=-1){
			nxt[lst[a[i]]]=i;
		}
		lst[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(nxt[i]==-1) continue;
		int d=query(1,1,n,i);
		modify(1,1,n,i,nxt[i]-1,i-d);
//		for(int j=i+1;j<nxt[i];j++){
//			d[j]+=(i-d[i]);
//		}
//		d[i]=i;
	}
	for(int i=1;i<=n;i++){
		ans[a[i]]=max(ans[a[i]],i-query(1,1,n,i));
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
//	fclose(stdin);
//	freopen("card1.ans","r",stdin);
//	for(int i=1;i<=m;i++){
//		int x;
//		cin>>x;
//		if(x!=ans[i]) {
//			cout<<"Wrong answer on "<<i<<endl;
//			cout<<"expect: "<<x<<endl;
//			cout<<"out: "<<ans[i];
//			return 0;
//		}
//	}
//	cout<<"Accept";
		
	return 0;
}
