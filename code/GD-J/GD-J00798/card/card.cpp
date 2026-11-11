#include<bits/stdc++.h>
using namespace std;
constexpr int N=5e5+10;
constexpr int M=3e5+10;
typedef long long ll;
int card[N];
int lst[M],ans[M];//cnt[i],最后一个i之后，有多少个数是“最后的 ” 包括他自己 
int bucket[M];
struct node{
	int id,pos;
}a[M];
bool cmp(node x,node y){
	return x.pos<y.pos;
}
void solve(){
	a[0]={0,0};
	memset(lst,-1,sizeof lst);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>card[i];
	for(int i=1;i<=n;++i) lst[card[i]]=i,bucket[card[i]]++;
	for(int i=1;i<=m;++i) a[i].id=i,a[i].pos=lst[i];
//	for(int i=1;i<=n;++i){
//		int j=i;
//		while(j<=n){
//			brute:
//				if(j>n) break;
//				while(lst[j]!=-1) j=lst[j];	
//				ans[j]++;
//			++j;
//			goto brute;			
//		}
//		
//	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;++i) cout<<a[i].id<<a[i].pos<<endl;
	for(int i=1;i<=m;++i) ans[a[i].id]=ans[a[i-1].id]+bucket[a[i].id];
	for(int i=1;i<=m;++i) cout<<ans[i]<<" ";
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	solve();
} 
/*
4 3
1 2 1 3
3 1 4

10 3
3 1 2 1 3 2 3 1 2 1

*/
