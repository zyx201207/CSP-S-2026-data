#include<bits/stdc++.h>
using namespace std;
int w[500005],k[505],a[505][50005],t[505][50005],x[100005],y[100005],v[10005][10005];
int main(){
   freopen("subway.in","r",stdin);
   freopen("subway.out","w",stdout);
	int i,l,j,n,m,c,d,q,p=0,T=0,A=0;
	cin>>c>>n>>m>>d>>q;
	memset(v,0x3f,sizeof(v));
	for(i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(i=1;i<=n;i++){
		scanf("%d",&k[i]);
		if(k[i]>2) A=1;
		for(j=1;j<=k[i];j++){
			scanf("%d%d",&a[i][j],&t[i][j]);
			if(p!=t[i][j]) T++,p=t[i][j];
		}
	}
	for(i=1;i<=q;i++){
		scanf("%d%d",&x[i],&y[i]);
	}
//	if(A==0){
//		queue<int> mq;
//		vector<int> nq[10005]={};
//		int b[1005][1005]={};
//		for(i=1;i<=n;i++){
//			if(k[i]==2){
//				nq[a[i][1]].push_back(a[i][2]);
//				nq[a[i][2]].push_back(a[i][1]);
//			}
//		}
//		for(i=1;i<=m;i++){
//			mq.push(i);
//			b[top]=1;
//			while(!mq.empty()){
//				int top=mq.front();
//				mq.pop();
//				for(i=0;i<nq[top].size();i++){
//					if(b[nq[top][i]]==1) continue;
//					mq.push(nq[top][i]);
//					b[nq[top][i]]=1;
//				}
//			}
//		}
//		return 0;
//	}
//	if(T==1){
//		
//		return 0;
//	}
	for(i=1;i<=m;i++){
		v[i][i]=0;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=k[i];j++){
			for(l=i;l<=k[i];l++){
				int q=a[i][j],p=a[i][l];
				v[q][p]=min(v[q][p],t[i][j]+t[i][l]);
				v[p][q]=v[q][p];
			}
		}
	}
//	for(i=1;i<=m;i++){
//		for(j=1;j<=m;j++){
//			cout<<v[i][j]<<"   ";
//		}
//		cout<<endl;
//	}
	for(l=1;l<=m;l++){
		for(i=1;i<m;i++){
			for(j=i+1;j<=m;j++){
				v[i][j]=min(v[i][j],v[i][l]+v[l][j]);
				v[j][i]=v[i][j];
			}
		}
	}
	for(i=1;i<=q;i++){
		printf("%d\n",v[x[i]][y[i]]+w[x[i]]+w[y[i]]);
	}
	return 0;
}
