#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,x[2000005],ans;
int l[2000005],r[2000005];
long long gl[2000005],gr[2000005],gs[2000005];
int le[2000005],re[2000005],cf[2000005],mg[2000005],pnt;
int dis[2000005],cnt[2000005];
void ad(int x){
	pnt+=cf[x];pnt+=mg[x];
	if(cf[x]<0)mg[x-1]-=cf[x];
	cf[l[x]-1]--;pnt++;
}void de(int x){
	if(l[x+1]>l[x] && l[x]<x){
		cf[l[x+1]-1]+=mg[x];
		cf[l[x]]-=mg[x];
	}pnt-=mg[x];
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;ans=0ll;
		for(int i=1;i<=n;i++)cin>>x[i];
		int pos=1;
		for(int i=1;i<=n;i++){
			while(x[i]-x[pos]>d)pos++;
			l[i]=pos;
		}pos=n;
		for(int i=n;i>=1;i--){
			while(x[pos]-x[i]>d)pos--;
			r[i]=pos;
		}
		if(n<=5000){
			for(int i=1;i<=n;i++){
				queue<int>q;
				q.push(i);
				for(int j=1;j<=n;j++)dis[j]=cnt[j]=0;
				dis[i]=1;cnt[i]=1;
				while(q.size()){
					int u=q.front();q.pop();
					for(int j=u+1;j<=r[u];j++){
						if(dis[j]==0){
							dis[j]=dis[u]+1;
							q.push(j);
						}if(dis[j]==dis[u]+1)cnt[j]=min(3,cnt[j]+cnt[u]);
					}
				}for(int j=1;j<=n;j++){
					if(cnt[j]==2)ans++;
				}
			}cout<<ans<<endl;
			continue;
		}
		for(int i=0;i<=n;i++)gl[i]=gr[i]=0ll;
		for(int i=1;i<=n;i++){
			gl[i]++;
			if(i<r[i])gl[r[i]]+=gl[i]; 
		}for(int i=n;i>=1;i--){
			gr[i]++;
			if(l[i]<i)gr[l[i]]+=gr[i];
		}
		for(int i=1;i<=n;i++)gs[i]=gs[i-1]+1ll*gr[i];
		gs[n+1]=gs[n];
		int pi=1,qi=1;
		for(int i=1;i<=n;i++){
			if(r[i]>i+1){
				while(pi<=n && (l[pi]<r[i]-1 || pi<=r[i]))pi++;
				while(qi<=n && (l[qi]<=r[i]-1 || qi<=r[i]))qi++;
				le[i]=pi;re[i]=qi; 
			}
		}
		for(int i=1;i<=n;i++)cf[i]=mg[i]=0ll;
		pi=qi=n;pnt=0;
		for(int i=n;i>=1;i--){
			if(le[i]>0){
				while(pi>le[i]){
					pi--;
					ad(pi);
				}while(qi>re[i]){
					de(qi);
					qi--;
				}
			//	ans+=1ll*gl[i]*(gs[re[i]-1]-gs[le[i]-1]);
				ans+=1ll*gl[i]*pnt;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}/*
0 1
7 7
1 8 14 15 16 17 23

2-3-5(2-4-5)
2-3-6(2-4-6)
2-3-5-7(2-4-5-7)
1-2-3-5(1-2-4-5)
1-2-3-6(1-2-4-6)
1-2-3-5-7(1-2-4-5-7)
X->Y
X->A->p->B->Y
X->A->q->B->Y
X->A:1
A->B:2
B->Y:1
*/
