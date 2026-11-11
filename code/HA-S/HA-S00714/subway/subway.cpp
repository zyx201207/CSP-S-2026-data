#include<bits/stdc++.h>
using namespace std;
const int N=20505,inf=INT_MAX/2;
int c,n,m,d,q;
int w[N],k,dis[N][N],a[N],t[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n+m;i++){
		for(int j=1;j<=n+m;j++){
			dis[i][j]=inf;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			dis[a[j]][m+i]=t[j];
			dis[m+i][a[j]]=t[j];
		}
	}
//	cout<<endl;
//	for(int i=1;i<=m+n;i++){
//		for(int j=1;j<=m+n;j++){
//			if(dis[i][j]!=INT_MAX/2)cout<<dis[i][j]<<" ";
//			else cout<<"X ";
//		}
//		cout<<endl;
//	}
	for(int k=1;k<=n+m;k++){
		for(int i=1;i<=n+m;i++){
			for(int j=i+1;j<=n+m;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				dis[j][i]=dis[i][j];
			}
		}
	}
//	cout<<endl;
//	for(int i=1;i<=m+n;i++){
//		for(int j=1;j<=m+n;j++){
//			if(dis[i][j]!=INT_MAX/2)cout<<dis[i][j]<<" ";
//			else cout<<"X ";
//		}
//		cout<<endl;
//	}
	
	for(int i=1,a,b;i<=q;i++){
		scanf("%d %d",&a,&b);
		printf("%d\n",dis[a][b]+w[a]+w[b]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
//7.184s,5.245s,5.021s
//Maybe I should use the djstl
