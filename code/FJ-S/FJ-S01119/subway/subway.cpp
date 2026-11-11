#include<bits/stdc++.h>
using namespace std;
long long n,m,d,q;
long long w[50050],kt[510][50010],ans=0x3f3f3f3f;
struct mar{
	long long resg;
	long long fla;
}g[505][505];
struct l{
	long long resk;
	long long le;
}k[505][50010];
long long sta[50010][505],le2[50010],be,ed;
inline long long read(){
	long long x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f; 
}
long long mi(long a,long b){
	if(a<=b)return a;
	return b;
}
long long mak(long long a,long long b,long c){
	long long res=0;
	res+=g[a][b].resg;
	if(g[a][b].fla!=c){
		res+=kt[b][c];
	}
	return res;
}
int main(){
	//ios::sync_with_stdio(0);
	//cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c;
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		long long t=read();
		for(int j=1;j<=t;j++){
			long long a,b;
			a=read();
			b=read();
			kt[i][a]=b;
			k[i][j].resk=a;
			le2[a]++;
			sta[a][le2[a]]=i;
		}
		k[i][1].le=t;
	}
	for(int i=1;i<=n-1;i++){
		for(int j=i+1;j<=n;j++){
			long long re=-1,flag1,flag2;
			for(int z=1;z<=k[i][1].le;z++){
				for(int z2=1;z2<=k[j][1].le;z2++){
					if(k[i][z].resk==k[j][z2].resk){
						if(re<=(kt[i][k[i][z].resk]+kt[j][k[j][z2].resk])){
							re=kt[i][k[i][z].resk]+kt[j][k[j][z2].resk];
							flag1=k[i][z].resk;
							flag2=k[j][z2].resk;
						}
					}
				}
			}
			g[i][j].resg=re;
			g[j][i].resg=re;
			g[j][i].fla=flag1;
			g[i][j].fla=flag2;
		}
	}
	while(q--){
		ans=0x3f3f3f3f;
		be=read();
		ed=read();
		bool f=0;
		for(int i=1;i<=le2[be];i++){
			for(int j=1;j<=le2[ed];j++){
				if(sta[be][i]==sta[ed][j]){
					ans=mi(ans,kt[sta[be][i]][be]+kt[sta[ed][j]][ed]);
					f=1;
				}
			}
		}
		if(f){
			cout<<ans+w[be]+w[ed]<<endl;
			continue;
		}
		if(!f){
			for(int i=1;i<=le2[be];i++){
				for(int j=1;j<=le2[ed];j++){
					long long res=0x3f3f3f3f;
					long long flag;
					if(res>=g[sta[be][i]][sta[ed][j]].resg){
						res=g[sta[be][i]][sta[ed][j]].resg;
						flag=sta[ed][j];
					}
					ans=mi(ans,mak(sta[be][i],sta[ed][j],ed));
				}
			}
		}
		cout<<ans+w[be]+w[ed]<<endl;
	}
	return 0;
}
