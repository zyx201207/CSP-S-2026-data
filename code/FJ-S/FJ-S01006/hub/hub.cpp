#include<bits/stdc++.h>
using namespace std;
long long id,T,n,m,k,x,y,z,l,r,mid,cnt,ss,sss,ans,s[1000005],a[1000005],b[1000005],p[1000005],v[1000005];
vector<long long>d[1000005];
void dfs(long long x,long long fa){
	b[x]=1;
	for(int i=0;i<d[x].size();i++)
		if(d[x][i]!=fa&&a[d[x][i]]==1)
		    dfs(d[x][i],x);
}
void _dfs(long long x,long long fa){
	p[x]=p[fa]+1;
	for(int i=0;i<d[x].size();i++)
		if(d[x][i]!=fa)
		    _dfs(d[x][i],x);
}
long long read(){
	long long ans=0;
	char c=0;
	bool f=0;
	while(c<'0'||c>'9')c=getchar(),f|=(c=='-');
	while(c>='0'&&c<='9')ans=ans*10+c-'0',c=getchar();
	return f?-ans:ans;
}
void write(long long x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	id=read(),T=read();
	if(1<=id&&id<=3){
		while(T--){
			n=read(),k=read(),ans=1e18;
			for(int i=1;i<=n;i++)d[i].clear();
			for(int i=1;i<n;i++)x=read(),y=read(),d[x].push_back(y),d[y].push_back(x);
			for(int i=0;i<(1<<n);i++){
				cnt=0;
				for(int j=1;j<=n;j++)a[j]=((i>>(j-1))&1),b[j]=0,cnt+=a[j];
				if(cnt==k){
					cnt=0;
					for(int j=1;j<=n;j++)
						if(a[j]&&!b[j])
							cnt++,dfs(j,0);
					if(cnt<=2){
						ss=0;
						for(int j=1;j<=n;j++){
							p[0]=-1,_dfs(j,0),sss=1e18;
							for(int k=1;k<=n;k++)
							    if(a[k]==1)
							        sss=min(sss,p[k]);
							ss=max(ss,sss);
						}
						ans=min(ans,ss);
					}
				}
			}
			write(ans),putchar('\n');
		}
		return 0;
	}
	while(T--){
		n=read(),k=read();
		for(int i=1;i<=n;i++)d[i].clear();
		for(int i=1;i<n;i++)x=read(),y=read(),d[x].push_back(y),d[y].push_back(x);
		if(n==k)putchar('0'),putchar('\n');
		else{
			m=n/2;
			if(k>=m)putchar('1'),putchar('\n');
			else write((m-k+3)/4+1),putchar('\n');
		}
	}
	return 0;
}

