#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y,cnt=0,k[500005],dis[500005],to[500005],vail[500005],nxt[500005],h[500005],w[500005],a[505][50005],t[505][50005];
bool b[500005];
void add(int a,int b,int c){
	to[++cnt]=b;
	vail[cnt]=c;
	nxt[cnt]=h[a];
	h[a]=cnt;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			for(int l=j+1;l<=k[i];l++){
				add(a[i][j],a[i][l],t[i][j]+t[i][l]);
				add(a[i][l],a[i][j],t[i][j]+t[i][l]);
				
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		int s=w[x]+w[y];
		for(int j=1;j<=m;j++){
			dis[j]=INT_MAX;
			b[j]=0;
		}
		dis[x]=0;
		for(int j=1;j<m;j++){
			int s1=INT_MAX,s2;
			for(int l=1;l<=m;l++){	
				if(dis[l]<s1&&b[l]==0){
					s1=dis[l];
					s2=l;
				}
			}
			b[s2]=1;
			for(int l=h[s2];l!=0;l=nxt[l]){
				if(b[to[l]]==0)
					dis[to[l]]=min(dis[to[l]],dis[s2]+vail[l]);
			}
		}
		s+=dis[y];
		cout<<s<<endl;
	}
	return 0;
}

