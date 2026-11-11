#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	return x*f;
}
#define N 2000010
int c,T;
int n,d;
int a[N];
int dis[N],cnt[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),T=read();
	while(T--){
		n=read(),d=read();
		for(int i=1;i<=n;i++)a[i]=read();
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[j]=LLONG_MAX;cnt[j]=0;
			}
			dis[i]=0;
			cnt[i]=1;
			for(int j=i;j<=n;j++){
				if(dis[j]==LLONG_MAX)break;
				for(int x=j+1;a[x]-a[j]<=d&&x<=n;x++){
					if(dis[x]>dis[j]+1){
						cnt[x]=cnt[j],
						dis[x]=dis[j]+1;
					}
					else if(dis[x]==dis[j]+1)
						cnt[x]+=cnt[j];
					;
//					dis[x]=min(dis[x],dis[j]+1);
				}
			}
			for(int j=i;j<=n;j++){
				if(cnt[j]==2)ans++;	
			}
//			for(int j=i;j<=n;j++)cout<<dis[j]<<" ";cout<<endl;
//			for(int j=i;j<=n;j++)cout<<cnt[j]<<" ";cout<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
0 1
10 272727272727272724
-999999999999999976 -727272727272727252 -454545454545454528 -181818181818181804 -90909090909090896 12 181818181818181828 454545454545454552 727272727272727276 1000000000000000000

0 1
10 3
0 3 6 9 10 11 13 16 19 22
-10 -7 -4 -1 0 1 3 6 9 12
*/
