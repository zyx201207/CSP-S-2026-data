#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500010];
const int inf=5e17;
//bool ck(int len){
//	int lsm=0,rsm=0;
//	//l:len/2(ceil) r:len/2(floor)
//	int ln=(len+1)>>1,rn=len>>1;
//	for(int i=1;i<=ln;i++){
//		lsm+=a[i];
//	}
//	for(int i=ln+1;i<=ln+rn;i++){
//		rsm+=a[i];
//	}
//	int pmd=ln;
//	int mnv=inf;
////	cout<<1<<","<<ln+rn<<","<<pmd<<","<<a[pmd]<<","<<lsm<<","<<rsm<<","<<ln*a[pmd]-lsm+rsm-rn*a[pmd]<<"\n";
//	mnv=min(mnv,ln*a[pmd]-lsm+rsm-rn*a[pmd]);
//	for(int i=2;i+len-1<=n;i++){
//		lsm-=a[i-1];
//		++pmd;
//		rsm-=a[pmd];
//		lsm+=a[pmd];
//		rsm+=a[pmd+rn];
//		mnv=min(mnv,ln*a[pmd]-lsm+rsm-rn*a[pmd]);
////		cout<<i<<","<<i+ln+rn-1<<","<<pmd<<","<<a[pmd]<<","<<lsm<<","<<rsm<<","<<ln*a[pmd]-lsm+rsm-rn*a[pmd]<<"\n";
//	}
//	cout<<"cal "<<len<<"::"<<mnv<<"\n";
//	return mnv<=m;
//}
queue<int>q;
int smt=0;
void work(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	q.push(0);
	int ans=1;
	int ssm=0;
	for(int i=2;i<=n;i++){
		ssm+=(a[i]-a[i-1])*q.size();
//		smt+=a[i]-a[i-1];
		smt=a[i]-a[1];
		q.push(a[1]-a[i]);
		while(ssm>m){
			int v=q.front();
			q.pop();
			ssm-=v+smt;
		}
		ans=max(ans,(int)q.size());
	}
	cout<<ans<<"\n";
//	int vmd=a[(n+1)>>1],res=0; 
//	for(int i=1;i<=n;i++){
////		cout<<a[i]<<",";
//		res+=abs(a[i]-vmd);
//		cout<<res<<",";
//	}
//	cout<<"\n";
//	cout<<res<<":::::\n";
//	cout<<"\n";
	//bin md
	//ck
	//medium
	//nonono
	//only add
//	int l=1,r=n;
//	while(l<r){
//		int md=(l+r+1)>>1;
//		if(ck(md))l=md;
//		else r=md-1;
//	}
//	cout<<l<<"\n";
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	while(t--){
		work();	
	}
}
/*
-52096*1251=-65172096
 
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

6 5
1 2 3 4 5 6


*/
