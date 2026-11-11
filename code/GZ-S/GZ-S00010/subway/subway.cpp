//GZ-S00010 黎平县第二中学 唐启谦
#include<iostream>
#include<cstring>
using namespace std;
int a[1001][1001],n,m,q,k,x[500000],y[500000],w[1001],b[1001][1001];
void floyd(){
	for(int i=0;i<m;i++){
		memset(b,0,sizeof(b));
		for(int j=1;j<=m;j++)for(int k=1;k<=m;k++)for(int l=1;l<=m;l++)if(j!=k&&a[j][l]!=-1&&a[l][k]!=-1&&(a[j][l]+a[l][k]<a[j][k]||a[j][k]==-1))b[j][k]=a[j][l]+a[l][k];
		for(int j=1;j<=m;j++)for(int k=1;k<=m;k++)if(b[j][k]!=0)a[j][k]=b[j][k];
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>n>>m>>q>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=m;i++)for(int j=1;j<=m;j++)a[i][j]=-1;
	for(int i=0;i<n;i++){
		cin>>k;
		for(int j=0;j<k;j++)cin>>x[j]>>y[j];
		for(int j=0;j<k;j++)for(int p=j+1;p<k;p++)a[x[j]][x[p]]=(a[x[j]][x[p]]==-1?y[j]+y[p]:min(a[x[j]][x[p]],y[j]+y[p]));
	}floyd();
	//for(int i=1;i<=m;i++){
	//	for(int j=1;j<=m;j++)cout<<a[i][j]<<' ';
	//	cout<<endl;
	//}
	while(q--){
		cin>>n>>k;
		cout<<w[n]+w[k]+a[n][k]<<endl;
	}return 0;
}
