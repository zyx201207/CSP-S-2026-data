#include<bits/stdc++.h>
#define int long long
using namespace std;
int rd(){
	int x=0;bool w=0;char c=getchar();
	while(c<'0'||c>'9')  c=='-'?w=1:0,c=getchar();
	while(c>='0'&&c<='9')  x=x*10+(c-48),c=getchar();
	return w?-x:x;
}
const int N=2e6+5;
int n,d,x[N],pre[N],nxt[N],s1[N],s2[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
for(int TC=rd(),T=rd();T--;){
	n=rd(),d=rd();
	for(int i=1;i<=n;i++)  x[i]=rd();
	x[0]=x[1]-d-1,x[n+1]=x[n]+d+1;
	for(int i=1,j=0;i<=n;i++){
		for(;x[i]-x[j]>d;j++);
		pre[i]=j;
	}
	for(int i=n,j=n+1;i>=1;i--){
		for(;x[j]-x[i]>d;j--);
		nxt[i]=j;
	}
	for(int i=1;i<=n;i++){
		s1[i]=0;
		if(pre[i]==i)  continue;
		s1[i]=pre[i+1]-pre[i];
		if(pre[i+1]!=pre[i])  s1[i]+=s1[pre[i]];
	}
	for(int i=n;i>=1;i--){
//		s2[i]=nxt[i]-i;
//		if(nxt[nxt[i]]!=nxt[i]&&nxt[nxt[i]]!=nxt[nxt[i]-1]){
//			s2[i]+=s2[nxt[i]]-(nxt[nxt[i]-1]-nxt[i]);
//		}
		s2[i]=0;
		if(nxt[i]==i)  continue;
		s2[i]=nxt[i]-nxt[i-1];
		if(nxt[i]!=nxt[i-1])  s2[i]+=s2[nxt[i]];
	}
//	for(int i=1;i<=n;i++)  cout<<nxt[i]<<" ";cout<<endl;
//	for(int i=1;i<=n;i++)  cout<<s2[i]<<" ";cout<<endl;
//	for(int i=1;i<=n;i++)  cout<<pre[i]<<" ";cout<<endl;
//	for(int i=1;i<=n;i++)  cout<<s1[i]<<" ";cout<<endl;
	int ans=0;
	for(int i=1;i<=n;i++){
		int j=nxt[i],k=j-1,l=k-1;
		if(j==i||k==i||nxt[k]==j)  continue;
//		cout<<"work : "<<i<<" "<<j<<" "<<k<<endl;
		ans+=nxt[k]-max(j,nxt[l]); // neither
		bool cond1=(nxt[j]==nxt[k]&&nxt[l]!=nxt[k]),
			 cond2=(i==1||nxt[i-1]<k);
		// only right
		if(cond1){
			ans+=s2[nxt[k]];
		}
		// only left
		if(cond2){
			ans+=s1[i]*(nxt[k]-max(j,nxt[l]));
		}
		// both
		if(cond1&&cond2){
			ans+=s1[i]*s2[nxt[k]];
		}
//		cout<<ans<<endl;
	}
	printf("%lld\n",ans);
}
	return 0;
}
/*
0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
*/
// 华风夏韵，洛水天依
