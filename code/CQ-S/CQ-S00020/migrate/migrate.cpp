#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
const int N=2e6+10;
int n,L[N],R[N],dep[N];ll ans,d,a[N];
int fa[N][23],pf[N],fd[N],tp[N],s1[N],s2[N],s3[N];
int iL[N],po[N];
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=22;i>=0;i--)if(dep[fa[x][i]]>=dep[y])
		x=fa[x][i];
	if(x==y)return x;
	for(int i=22;i>=0;i--)if(fa[x][i]!=fa[y][i])
		x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
struct str{
	int x,y,z;
};
str mx[N][23];
int tmpadd[10];
str add(str x,str y){
	tmpadd[1]=x.x;
	tmpadd[2]=x.y;
	tmpadd[3]=x.z;
	tmpadd[4]=y.x;
	tmpadd[5]=y.y;
	tmpadd[6]=y.z;
	sort(tmpadd+1,tmpadd+7);
	str z;
	z.x=tmpadd[6],z.y=tmpadd[5],z.z=tmpadd[4];
	// cout<<x.x<<" "<<x.y<<" "<<x.z<<"  "<<y.x<<" "<<y.y<<" "<<y.z<<"  "<<z.x<<" "<<z.y<<" "<<z.z<<endl;
	return z;
}
str ask(int x,int y){
	str an;an.x=an.y=an.z=0;
	for(int i=22;i>=0;i--){
		int p=fa[x][i];
		if(dep[p]>=dep[y]){
			an=add(an,mx[x][i]);
			x=p;
		}
	}
	return an;
}
ll fs2[N][23],fs1[N][23];int pos[N][23];

void sol(){
	// cout<<n<<" :";
	// for(int i=1;i<=n;i++)
	// 	cout<<a[i]<<" ";;cout<<endl;
	// for(int i=1;i<=n;i++)
	// 	cout<<a[i]-a[1]<<" ";;cout<<endl;
	for(int i=1;i<=n;i++){
		L[i]=i,R[i]=i;
		for(int j=22;j>=0;j--){
			int mid=L[i]-(1<<j);
			if(mid<1)continue;
			if(a[i]-a[mid]<=d)L[i]=mid;
		}
		for(int j=22;j>=0;j--){
			int mid=R[i]+(1<<j);
			if(mid>n)continue;
			if(a[mid]-a[i]<=d)R[i]=mid;
		}
	}
	// cout<<"L:";for(int i=1;i<=n;i++)cout<<L[i]<<" ";;cout<<endl;
	// cout<<"R:";for(int i=1;i<=n;i++)cout<<R[i]<<" ";;cout<<endl;
	for(int i=n;i>=1;i--){
		dep[i]=dep[R[i]]+1;
		fa[i][0]=R[i];
		// cout<<i<<" "<<R[i]<<endl;exit(0);
		for(int j=1;j<=22;j++){
			// cout<<i<<" "<<j<<" "<<fa[i][j-1]<<endl;
			fa[i][j]=fa[fa[i][j-1]][j-1];
		}
	}
	pf[n]=n;
	for(int i=n-1;i>=1;i--){
		pf[i]=pf[R[i]];int f=R[i];
		if(f!=i+1&&dep[f-1]==dep[f]&&dep[lca(f-1,f)]>=dep[pf[f]]){
			// cout<<"! "<<i<<endl;
			int lc=lca(f-1,f);
			pf[i]=i;
			for(int j=22;j>=0;j--)
				if(dep[fa[pf[i]][j]]>dep[lc])
					pf[i]=fa[pf[i]][j];
		}
	}
	// cout<<"pf:";for(int i=1;i<=n;i++)cout<<pf[i]<<" ";;cout<<endl;
	for(int i=1;i<=n;i++){
		int fl=1,lt=lca(i,i-1);
		if(dep[i]!=dep[i-1])fl=0;
		if(R[i-1]!=i&&dep[lt]<dep[pf[i-1]])fl=0;
		if(R[i-2]>i&&dep[i-2]==dep[i]&&lca(i-2,i)==lt){
			if(fl)po[i]=1;
			fl=0;
		}
		if(fl)fd[i]=dep[lt];
	}
	// cout<<"fd:";for(int i=1;i<=n;i++)cout<<fd[i]<<" ";;cout<<endl;
	// cout<<"po:";for(int i=1;i<=n;i++)cout<<po[i]<<" ";;cout<<endl;
	for(int i=n;i>=1;i--){
		mx[i][0]={fd[i],0,0};int nw=0;
		for(int j=1;j<=22;j++){
			if(fa[i][j]<n){
				mx[i][j]=add(mx[i][j-1],mx[fa[i][j-1]][j-1]);
			}
			else{
				if(!nw)mx[i][j]=add(mx[i][j-1],mx[fa[i][j-1]][j-1]),nw=1;
				else mx[i][j]=mx[i][j-1];
			}
		}
	}
	for(int i=n-1;i>=1;i--){
		tp[i]=R[i];str p;p.x=p.y=p.z=0;
		for(int j=22;j>=0;j--){
			if(fa[tp[i]][j]==tp[i])continue;
			int md=fa[tp[i]][j];
			str q=add(p,mx[tp[i]][j]);
				// if(i==6){
				// 	cout<<"% "<<i<<" "<<md<<" "<<q.y<<endl;
				// }
			if(q.y<dep[md]){
				tp[i]=md,p=q;
			}
		}
	}
	for(int i=1;i<=n;i++)if(!iL[L[i]])iL[L[i]]=i;
	for(int i=1;i<=n;i++)if(!iL[i])iL[i]=N;
	// cout<<"iL:";for(int i=1;i<=n;i++)cout<<iL[i]<<" ";;cout<<endl;
	for(int i=1;i<n;i++){
		int j=iL[i];
		s1[i]=max(0,R[i]-j+1);
		j=R[i];
		if(j>=i+2&&L[j-1]==i){
			int x=max(iL[j-1],j+1);
			int y=min(R[j],iL[j]-1);
			s2[i]=max(0,y-x+1);
		}
		if(j>=i+2){
			int x=max(iL[j-1],j+1);
			int y=min(R[j],iL[j]-1);
			s3[i]=max(0,y-x+1);
		}
		// cout<<i<<" "<<s1[i]<<" "<<s2[i]<<" "<<s3[i]<<endl;
	}
	for(int i=n;i>=1;i--){
		fs1[i][0]=s1[i];fs2[i][0]=s2[i];pos[i][0]=po[i];
		for(int j=1;j<=22;j++){
			fs1[i][j]=fs1[i][j-1]+fs1[fa[i][j-1]][j-1];
			fs2[i][j]=fs2[i][j-1]+fs2[fa[i][j-1]][j-1];
			pos[i][j]=pos[i][j-1]+pos[fa[i][j-1]][j-1];
		}
	}
	// cout<<"tp:";for(int i=1;i<=n;i++)cout<<tp[i]<<" ";;cout<<endl;
	for(int i=1;i<n;i++){
		int p=i;
		// while(p!=pf[i]){
		// 	if(p!=i){
		// 		ans+=s2[p];
		// 	}
		// 	else{
		// 		ans+=s3[p];
		// 	} 
		// 	p=R[p];
		// }
		// if(po[p])continue;
		// p=R[p];
		// while(p!=R[tp[i]]&&!po[p]){
		// 	ans+=s1[p];
		// 	p=R[p];
		// }


		if(p!=pf[i]){
			ans+=s3[p];
			p=R[p];
			if(p!=pf[i]){
				for(int j=22;j>=0;j--){
					if(dep[fa[p][j]]>dep[pf[i]]){
						ans+=fs2[p][j];
						p=fa[p][j];
					}
				}
				while(p!=pf[i]){
					ans+=s2[p];
					p=R[p];
				}
			}
		}
		if(po[p])continue;
		p=R[p];
		for(int j=22;j>=0;j--){
			int t=fa[p][j];
			if(dep[t]>=dep[tp[i]]&&pos[p][j]==0){
				ans+=fs1[p][j];p=t;
			}
		}
	}
	// puts("NO"); exit(0);
	for(int i=1;i<=n;i++){
		a[i]=L[i]=R[i]=dep[i]=pf[i]=fd[i]=tp[i]=0;
		s1[i]=s2[i]=iL[i]=s3[i]=po[i]=0;
		for(int j=0;j<=22;j++)
			fa[i][j]=0,mx[i][j]={0,0,0},pos[i][j]=fs1[i][j]=fs2[i][j]=0;
	}
	/*
	*/
}
void solve(){
	int nn;ans=0;
	scanf("%d%lld",&nn,&d);
	vector<ll>ve;ve.push_back(0);
	for(int i=1;i<=nn;i++){
		ll x;scanf("%lld",&x);
		ve.push_back(x);
	}
	for(int l=1,i=2;i<=nn+1;i++){
		if(ve[i]-ve[i-1]>d||i==nn+1){
			n=i-l;
			for(int j=1;j<=n;j++)
				a[j]=ve[l+j-1];
			sol();
			l=i;
		}
	}
	printf("%lld\n",ans);
	// exit(0);
}
#undef int 
int main(){
#define int long long 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--)solve();
	return 0;
}
/*

*/