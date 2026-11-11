#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+100;
int n,m,a[N],b[N],c[N],d[N],gt;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;int op=0,last=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n);
	if(n<25){
		int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=(1<<i)-1;j++){
			int an=0,op=0;
			for(int k=0;k<i;k++){
				if(j&(1<<k))an+=(a[i]-a[k+1]),op++;
			}
			if(an<=m)ans=max(ans,op);
		}
	}cout<<ans<<'\n';return 0;
	}
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];op+=b[i];
//		cout<<b[i]<<' ';
	}//cout<<op<<'\n';
	int o=0;
	for(int i=1;i<=n;i++){
		c[i]=op-b[i-1]-o;o+=b[i-1];
		d[i]=d[i-1]+c[i];//cout<<d[i]<<' '<<c[i]<<'\n';
	}
//	for(int i=n-1;i>=1;i--)c[i]=c[i+1]+c[i];
	d[n]=0;
	for(int i=n-1;i>=1;i--){
		int now=i,ans=0,an=0;
//		cout<<now<<' '<<now<<' '<<ans<<'\n';
		for(int j=5;j>=0;j--){//
//			cout<<now-(1<<j)-1<<' '<<now<<' '<<d[now]-d[now-(1<<j)-1]<<' '<<((1<<j)+1)*c[now+1]<<' '<<d[now]-d[now-(1<<j)-1]-((1<<j)+1)*c[now+1]+ans<<' '<<an<<'\n';
			if(now-(1<<j)-1>=0&&d[now]-d[now-(1<<j)-1]-((1<<j)+1)*c[now+1]+ans<=m)
			now=now-(1<<j)-1,ans=(d[now]-d[now-(1<<j)-1])-((1<<j)+1)*c[now+1],an+=(1<<j)+1;
		}
		if(now-1>=0&&d[now]-d[now-1]-c[now+1]+ans<=m)
			now=now-1,ans=(d[now]-d[now-1]),an+=1;
		if(an!=0)an+=1;
		gt=max(gt,an);
	}
	cout<<gt<<'\n';
	return 0;
}/*
5 10
4 0 19 1 0
5 8
-3 -1 2 2 7*/
