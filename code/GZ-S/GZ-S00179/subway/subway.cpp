//GZ-S00179 安顺开发区长水大洋实验学校 秦泽锦玥
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[1000005],a[1000005],t[10000005],b[10000005],u[10000005],r,p;
int k=0;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++)cin>>w[i];
	
	for(int i=0;i<n;i++){
	int o;
	cin>>o;
	u[i]=o;
	for(int j=k+1;j<=k+o;j++)cin>>a[j]>>t[j];
	k=k+o;
}
	u[0]=0;
	for(int i=1;i<=q;i++){
	int s=1;
	b[i]=0;
	cin>>r>>p;
	int z=u[s];
	for(int j=1;j<=z;j++){
		if(r==a[j]){
			b[i]+=w[j]+t[j];
			break;
		}
		if(j==z){
		s++;
		z+=u[s];
		}	
	}
	for(int j=u[s-1]+1;j<=z;j++){
	if(p==a[j])b[i]+=w[j]+t[j];
	else if(j==z){
	for(int v=1;v<=k;v++){
	if(a[j]==a[v]){
	b[i]+=t[v]+t[v+u[s]];
	b[i]+=t[p]+w[p];
	}
	}
	}
	
	}
	}
	for(int i=1;i<=q;i++)cout<<b[i]<<endl;
	
	

	return 0;
}
