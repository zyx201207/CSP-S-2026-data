#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0;
	char ch=getchar();
	while('0'>ch||ch>'9')ch=getchar();
	while('0'<=ch&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x;
}
long long n,m,a[200005];
long long ans;
void dfs(long long chs,long long sum,long long depth){
	if(sum==0)return;
	if(depth==m){
		ans=max(ans,sum);
		return;
	}
	long long t=sum;
	for(long long i=chs+1;i<=n;i++){
		t=sum;
		t&=a[i];
		//cout<<a[chs]<<" "<<a[i]<<endl;
		dfs(i,t,depth+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(),m=read();
	long long maxx=-1,minn=1e9;
	for(int i=1;i<=n;i++){
		a[i]=read();
		maxx=max(maxx,a[i]);
		minn=min(minn,a[i]);
	}
	if(m==2){
		maxx=-1;
		long long cnt;
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				cnt=a[i];
				cnt&=a[j];
				maxx=max(cnt,maxx);
			}
		}
		cout<<maxx;
	}else if(m==1){
		printf("%lld",maxx);
	}else if(m==n){
		long long cnt=a[1];
		for(int i=2;i<=n;i++){
			cnt&=a[i];
		}
		printf("%lld",cnt);
	}else{
		for(long long i=1;i<=n;i++){
			dfs(i,a[i],1);
		}
		printf("%lld",ans);
	}
	return 0;
}
//Trick||Treat!
// 4 2 3 15 12 12
//5 3 31 3 1 15 7
