#include<bits/stdc++.h>
#define ll long long
#define il inline
#define gc getchar
using namespace std;
int c,t;
ll res;bool f;char ch;
il ll rd(){
	res=0,f=0,ch=gc();
	while((ch<'0'||ch>'9')&&ch!='-') ch=gc();
	if(ch=='-') f=1,ch=gc();
	while(ch>='0'&&ch<='9') res=(res<<3)+(res<<1)+(ch&15),ch=gc();
	return f?-res:res;
}
const int N=2000000;
int n,nxt[N+5],p,lst,cur; 
int fa[N+5][21];
int c1[N+5][21],c2[N+5][21],c0[N+5][21];
int c3[N+5],c4[N+5],s3[N+5],s4[N+5];
int L1,R,R1,R2,R3;
ll d,x[N+5],ans;
void gans(int l,int r){
	for(int i=r;i>=l;i--){
		if(i>=l+1&&nxt[i-1]==nxt[i]) c1[i][0]=1;
		else c1[i][0]=0;
		if(i>=l+2&&nxt[i-2]==nxt[i]) c2[i][0]=1;
		else c2[i][0]=0;
		if(i>=l+1&&nxt[i-1]==nxt[i]-1&&nxt[nxt[i]-1]==nxt[nxt[i]]) c0[i][0]=1;
		else c0[i][0]=0;
		if(i==l) c3[i]=0;
		if(i==l+1) c3[i]=max(0,nxt[i-1]-i);
		if(i>=l+2) c3[i]=max(0,nxt[i-1]-max(i,nxt[i-2]));
		if(i==l) c4[i]=nxt[i]-i;
		else c4[i]=nxt[i]-max(i,nxt[i-1]);
		fa[i][0]=nxt[i];
		for(int j=1;j<21;j++){
			fa[i][j]=fa[fa[i][j-1]][j-1];
			c1[i][j]=c1[i][j-1]+c1[fa[i][j-1]][j-1];
			c2[i][j]=c2[i][j-1]+c2[fa[i][j-1]][j-1];
			c0[i][j]=c0[i][j-1]+c0[fa[i][j-1]][j-1];
		}
		if(i==r) continue;
		s3[i]=c3[i],s4[i]=c4[i];
		s3[i]+=s3[nxt[i]],s4[i]+=s4[nxt[i]];
		if(nxt[i-1]==nxt[i]-1) s3[i]-=c3[nxt[i]];
		p=nxt[i];
		for(int j=20;~j;j--)
			if(!c1[p][j])
				p=fa[p][j];
		L1=p;
		p=nxt[i],cur=0;
		for(int j=20;~j;j--)
			if(cur+c1[p][j]<=1)
				cur+=c1[p][j],p=fa[p][j];
		R1=p;
		p=nxt[i];
		for(int j=20;~j;j--)
			if(!c2[p][j])
				p=fa[p][j];
		R2=p;
		p=nxt[i];
		for(int j=20;~j;j--)
			if(!c0[p][j])
				p=fa[p][j];
		
		R3=p;
		R=min(R1,min(R2,nxt[R3]));
		ans+=s3[nxt[i]]-s3[nxt[L1]];
		ans+=s4[nxt[L1]]-s4[R];
	}
}
void solve(){
	n=rd(),d=rd(),ans=0;
	for(int i=1;i<=n;i++) x[i]=rd();
	lst=n+1,p=n;
	for(int i=n;i;i--){
		while(x[p]-x[i]>d) --p;
		nxt[i]=p;
		if(i==1||x[i]-x[i-1]>d) gans(i,lst-1),lst=i; 
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=rd(),t=rd();
	while(t--) solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
