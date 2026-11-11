#include<bits/stdc++.h>
#define int long long
//#define DEBUG
#ifdef DEBUG
#define debug(x...) fprintf(stderr,x);
#else
#define debug(x...) ((void)0)
#endif
using namespace std;
int n,m;
int a[200005];
int sum[35];
//multiset<int>st,tst;
int st[200005][2];
int len[2];
bool op=0;
inline bool query(int x,int i){//1<=i<=30
	return (x>>(i-1))&1;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=30;j++){
			sum[j]+=query(a[i],j);
		}
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		//st.insert(a[i]);
		st[++len[op]][op]=a[i];
	}
	for(int j=30;j>=1;j--){
		if(sum[j]>=m){
			//tst.clear();
			len[op^1]=0;
			//for(auto t:st){
			for(int i=1;i<=len[op];i++){
				int t=st[i][op];
				if(query(t,j)){
					st[++len[op^1]][op^1]=t;
					//tst.insert(t);
				}else{
					for(int k=1;k<=min(30ll,j+1);k++){
						sum[k]-=query(t,k);
					}
				}
			}
			//st=tst;
			op^=1;
		}
		debug("j:%d st:",j);
		//for(auto t:st){
		for(int i=1;i<=len[op];i++){
			int t=st[i][op];
			debug("%d ",t);
		}
		debug("\n");
	}
	int ans=(1<<30)-1;
	//for(auto t:st){
	for(int i=1;i<=len[op];i++){
		int t=st[i][op];
		ans&=t;
	}
	cout<<ans<<endl;
	return 0;
}
/*
0 0 1 1
1 1 1 1
1 1 0 0
1 1 0 0
*/
