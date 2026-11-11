#include<bits/stdc++.h>
using namespace std;
int n,m,a[233333],ans;
int read(){
	int res=0;char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch)){res=res*10+ch-'0';ch=getchar();}
	return res;
}
int main(){
	freopen("and.in","r",stdin);freopen("and.out","w",stdout);
	n=read();m=read();for(int i=1;i<=n;++i)a[i]=read();
	for(int i=30,cnt=0;~i;--i,cnt=0){
		for(int j=1;j<=n;++j)cnt+=(a[j]&1<<i)>0;
		if(cnt<m)continue;
		for(int j=1;j<=n;++j)if((a[j]&1<<i)==0)a[j]=0;
		ans|=1<<i;
	}
	printf("%d",ans);return 0;
}
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
