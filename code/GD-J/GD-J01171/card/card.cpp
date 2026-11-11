#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,m,a[N],b[N],q[N],su[N],qz[N],s[N],ss[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		qz[i]=b[a[i]];b[a[i]]=i;su[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		int t=0;
		for(int j=1;j<=m;j++)q[j]=0,ss[j]=0;
		for(int j=i;j<=n;j++){
			if(q[a[j]]!=0&&b[q[a[j]]]==a[j]&&q[a[j]]<t)t=q[a[j]];
			else t++,b[t]=a[j],q[a[j]]=t;
			//cout<<a[j]<<"*";
		}
		//cout<<t<<" ";
		for(int j=1;j<=t;j++)ss[b[j]]=1;//cout<<b[j]<<" ";
		for(int j=1;j<=m;j++)s[j]+=ss[j];
		//cout<<"\n";
	}
	for(int i=1;i<=m;i++)printf("%lld ",s[i]);
	return 0;
}
