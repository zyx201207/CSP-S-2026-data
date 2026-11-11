//毕节梁才学校
//罗悦辉
//GZ-S00393 
#include<bits/stdc++.h>
using namespace std;
#define LL long long 

int c,t;
int n;
const int N=2e6+10;

LL a[N],d;
int to[90010];
int nt[90010];
int h[310];
int idx;

void add(int x,int y){
	to[idx]=y;
	nt[idx]=h[x];
	h[x]=idx;
	idx++;
}

int dd[310];
bool v[310];
int num[310];
int q[9000010],tt=-1,hh=0;
void spfa(int u){
	memset(dd,0x3f,sizeof(dd));
	memset(v,0,sizeof(v));
	tt=-1,hh=0;
	q[++tt]=u;
	v[u]=true,num[u]=1,dd[u]=0;
	while(hh<=tt){
		int x=q[hh++];
		v[x]=false;
		for(int i=h[x];i!=-1;i=nt[i]){
			int j=to[i];
//			cout<<dd[j]<<' '<<x<<' '<<dd[x]<<' '<<j<<endl;
			if(dd[j]>dd[x]+1) {
				dd[j]=dd[x]+1,num[j]=num[x];
//				cout<<"EE"<<x<<' '<<j<<' '<<num[j]<<endl;
				if(!v[j]) v[j]=true,q[++tt]=j;
			}else if(dd[j]==dd[x]+1){
				num[j]+=num[x];
//				cout<<"EE"<<x<<' '<<j<<' '<<num[j]<<endl;
			}
		}
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	scanf("%d%d",&c,&t);
	while(t--){
		memset(h,-1,sizeof(h));
		idx=0;
		
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		
		if(n<=300){
			int cnt=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[j]-a[i]<=d) add(i,j);
				}
			}
			for(int i=1;i<=n;i++){
				spfa(i);
				for(int j=i+1;j<=n;j++){
					if(num[j]==2) cnt++;
//					cout<<i<<' '<<j<<' '<<num[j]<<endl;
				}
			}
			printf("%d\n",cnt);
			continue;
		}
		
	}
	
	return 0;
}
