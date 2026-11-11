#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],ans,p[N][2];
bool vis[40],f;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,i,now;
//	cin>>n;
//	bitset<5>s=n;
//	cout<<s;
	cin>>n>>m;
	for(i=1;i<=n;++i)
		cin>>a[i];
	for(i=31;i>=0;--i){
		now=1<<i;
		p[0][0]=0;
		for(int j=1;j<=n;++j)
			if(a[j]&now)
				p[++p[0][0]][0]=j;
		if(p[0][0]>=m)break;
	}
	ans=now;
	for(int k=i-1;k>=0;--k){
		now>>=1;
		p[0][!f]=0;
		for(int j=1;j<=p[0][f];++j)
			if(a[p[j][f]]&now)
				p[++p[0][!f]][!f]=p[j][f];
		if(p[0][!f]>=m){
			ans+=now;
			f=!f;
		}
	}
	cout<<ans;
	return 0;
}
/*
0011
1111
1100
1100
*/
