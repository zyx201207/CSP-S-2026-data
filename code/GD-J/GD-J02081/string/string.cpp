#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N=2e6+10,mod=998244353;
typedef pair<int,int> pii;
typedef long long ll;
/*

*/
int C,T=1,n;
ll lp[N],lq[N];
char cp[N],cq[N];
void mian(){
	cin>>n;
	for(int i=1;i<=n;i++) 
		cin>>lp[i]>>cp[i],
		lq[n-i+1]=lp[i],cq[n-i+1]=cp[i];
	for(int i=1;i<=n;i++) lp[i]+=lp[i-1],lq[i]+=lq[i-1];
	ll res=0,q=0,qp=1;
	for(int i=1;i<=n;i++){
		while(qp<=n&&lq[qp]<=lp[i]) res+=(lq[qp]-q)*(cq[qp]!=cp[i]),q=lq[qp],++qp;
		if(qp<=n&&q<lp[i]) res+=(lp[i]-q)*(cq[qp]!=cp[i]),q=lp[i];
	}
	cout<<res/2;
	return;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
//	cin>>C>>T;
	while(T--) mian();
	return 0;
}

