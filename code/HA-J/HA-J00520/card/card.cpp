#include<bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define dop(k,l,r) for(int k=l;k>=r;k--)
#define _ 200005
#define __ 100005
using namespace std;
////ll n,m,a[_],ans[_];
////int last[__],tot[_];
////bool vis[_],cnt[_];
////stack<int>card;
////pair<int,int>q[_];
////bool cmp(pair<int,int>x,pair<int,int>y){
////	return x.second<y.second;
////}
int n,m,a[_];
ll tot[_],b[_];
int main(){
	freopen("card.in" ,"r",stdin );
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		scanf("%d",&a[i]);
//		if(!vis[x]){
//			card.push(x);
//			vis[x]=true;
//			b[i][x]++;
//		}
//		else{
//			while(!card.empty()&&card.top()!=x){
//				int t=card.top();
//				card.pop();
//				b[i][t]--;
//				vis[t]=false;
//			}
//		}
	}
	rep(i,1,n)
		tot[a[i]]++;
	rep(i,1,m){
		b[i]=b[i-1]+tot[i];
	}
//	rep(i,1,n){
//		if(!last[a[i]])
//			last[a[i]]=i;
//		else
//		{
//			int l=last[a[i]]+1,
//				r=i;
//			q[++tot]={l,r};
//		}
//	}
//	sort(q+1,q+tot+1,cmp);
//	int pre=n;
//	dop(k,tot,1){
////		cout<<q[k].first<<' '<<q[k].second<<endl;
//		int i;
//		rep(i,1,n)
//			ans[a[i]]+=(pre-q[k].first+1)*(!cnt[i]);
//		rep(i,q[k].first,q[k].second);
//			cnt[i]=true;
//		pre=q[k].first;
//	} 
//	rep(i,1,n)
//		ans[a[i]]+=pre*(!cnt[i]);
////	rep(i,1,n)
////		rep(j,1,m)
////			b[i][j]+=b[i-1][j];
////	rep(i,1,n)
////		rep(j,1,m)
////			ans[j]+=b[i][j];
	rep(j,1,m)
		printf("%lld ",b[j]);
	return 0;
} 
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/
