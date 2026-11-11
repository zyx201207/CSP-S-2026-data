#include<bits/stdc++.h>
using namespace std;
int c,n,m,d2,q,a[500005],k;
struct xl{
    int x,j;
};
vector<xl> b[500005];
long long d[505][505],ans=0;    
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(d,0x3f,sizeof(d));
    cin>>c>>n>>m>>d2>>q;
    for(int i=1;i<=m;i++)
		scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
		scanf("%d",&k);
		int x,y;
		for(int j=1;j<=k;j++){
	    	scanf("%d%d",&x,&y);
	    	xl f; f.x=i; f.j=y;
	    	b[x].push_back(f);
		}
	}
    for(int i=1;i<=m;i++){
		for(int j=1;j<b[i].size();j++)
		    for(int f=0;f<j;f++)
				if(b[i][f].j+b[i][j].j<d[b[i][f].x][b[i][j].x]){
			    	d[b[i][f].x][b[i][j].x]=b[i][f].j+b[i][j].j;
			    	d[b[i][j].x][b[i][f].x]=b[i][f].j+b[i][j].j;
			    }
    }
    for(int i=0;i<=n;i++)
        d[i][i]=0;
	for(int l=1;l<n;l++)
        for(int i=1;i+l<=n;i++){
			int j=i+l;
	    	for(int f=i+1;f<j;f++)
				if(d[i][f]+d[f][j]<d[i][j]){
			    	d[i][j]=d[i][f]+d[f][j];
			    }
		}	
	int x,y;long long ans;
    for(int i=1;i<=q;i++){
		scanf("%d%d",&x,&y); ans=-1;
		if(x>y) swap(x,y);
		for(int j=0;j<b[x].size();j++)
		    for(int f=0;f<b[y].size();f++){
				long long h=d[b[x][j].x][b[y][f].x]+b[x][j].j+b[y][f].j;
		        if(ans==-1||ans>h)
		             ans=h;
			}
		printf("%lld\n",ans+a[x]+a[y]);
	}
    fclose(stdin); fclose(stdout);
    return 0;
}
