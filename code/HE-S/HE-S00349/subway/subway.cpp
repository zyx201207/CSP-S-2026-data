#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,r1,r2;
long long rds[502][502],w[500005];
int ks[500005][20],kt[500005];
long long rdk[502][500005];
bitset<502> u[500005];
int main()
{
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	memset(rds,63,sizeof(rds));
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=0;i<n;++i){
            rds[i][i]=0;
        cin>>k;
        for(int j=0;j<k;++j){
            cin>>r1>>r2;ks[r1][kt[r1]++]=i;
            if(u[i][r1]){rdk[i][r1]=(rdk[i][r1]>r2?r2:rdk[i][r1]);}
            else{u[i][r1]=1;rdk[i][r1]=r2;}
        }
	}
    for(int i=1;i<=m;++i)
        for(int j=0;j<kt[i];++j)
            for(int k=j+1;k<kt[i];++k)
            if(rds[ks[i][j]][ks[i][k]]>rdk[ks[i][j]][i]+rdk[ks[i][k]][i])rds[ks[i][j]][ks[i][k]]=rds[ks[i][k]][ks[i][j]]=rdk[ks[i][j]][i]+rdk[ks[i][k]][i];
	for(int i=0;i<n;++i) for(int j=i+1;j<n;++j) for(int k=0;k<i;++k){
            if(rds[i][j]>rds[i][k]+rds[j][k]) rds[j][i]=rds[i][j]=rds[i][k]+rds[j][k];
            if(rds[i][k]>rds[i][j]+rds[j][k]) rds[i][k]=rds[k][i]=rds[i][j]+rds[j][k];
            if(rds[j][k]>rds[k][i]+rds[i][j]) rds[j][k]=rds[k][j]=rds[k][i]+rds[i][j];
	}
	while(q--)
    {
        cin>>r1>>r2;long long ans=1ll<<62;
        for(int i=0;i<kt[r1];++i) for(int j=0;j<kt[r2];++j)
            ans=min(rds[ks[r1][i]][ks[r2][j]]+rdk[ks[r1][i]][r1]+rdk[ks[r2][j]][r2],ans);
        cout<<ans+w[r1]+w[r2]<<'\n';
    }
	fclose(stdin);fclose(stdout);
	return 0;
}
