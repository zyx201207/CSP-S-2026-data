#include<bits/stdc++.h>
#define int long long
//#define DEBUG
#ifdef DEBUG
#define debug(x...) fprintf(stderr,x);
#else
#define debug(x...) ((void)0)
#endif
using namespace std;
int n,m,nn;
struct node{
	char c;
	int b,e;
}a[200005],aa[1000005],ra[1000005];
set<int>st,sst;
int ast[1000005],len;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int aa;
		cin>>aa>>a[i].c;
		a[i].b=m+1;
		a[i].e=m+aa;
		st.insert(m+1);
		st.insert(m+aa);
		m+=aa;
	}
	for(auto t:st){
		sst.insert(t);
		sst.insert(m-t);
		debug("%d %d\n",t,m-t);
	}
	debug("\nast:");
	for(auto t:sst){
		ast[++len]=t;
		debug("%d ",t);
	}
	debug("\n");
	int j=1;
	for(int i=2;i<=len;i++){
		int t=ast[i];
		while(t>a[j].e) j++;
		aa[++nn].c=a[j].c;
		aa[nn].b=ast[i-1]+1;
		aa[nn].e=t;
	}
	
	for(int i=1;i<=nn;i++){
		ra[nn-i+1].b=m-aa[i].e+1;
		ra[nn-i+1].e=m-aa[i].b+1;
		ra[nn-i+1].c=aa[i].c;
	}
	int ans=0;
	for(int i=1;i<=nn;i++){
		if(aa[i].c!=ra[i].c) ans+=aa[i].e-aa[i].b+1;
		debug("%d %d %c  %d %d %c\n",aa[i].b,aa[i].e,aa[i].c,
		                             ra[i].b,ra[i].e,ra[i].c);
	}
	cout<<ans/2<<endl;
	return 0;
}
/*
aa bb c
a a b b c
 
aa aaa
aa a aa
*/
