//#include<bits/stdc++.h>
//using namespace std;
//int c,n,m,d,q;//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数。
//int w[500005];//表示从每个地铁站的地铁口走到站厅需要的时间
//int k,a[505][500005],t[505][500005];
////int x[100005],y[100005];
//int x,y;
//int minn[500005];
//bool f[500005];
//int ans;
//
//int a1,b1,tmp;
//
//int find(int num,int zhan){
//	for(int i=1;i<=n;i++){
//		if(a[num][i]==zhan){
//			
//			return i;
//		}
//	}return 0;
//}
//
//int atob(int ax,int by){
//	for(int i=1;i<=n;i++){
//		a1=find(i,ax);
//		b1=find(i,by);
//		
//		if(a1&&b1){
//			tmp=t[i][a1]+t[i][b1];
//			
//			return tmp;
//		}
//	}return 10000000LL;
//}
//
//
//
//void time(int start,int end){
//	
//	for(int i=1;i<=m;i++){
//		if(find(start,i)&&start!=i&&f[i]!=1){
//			
//			minn[i]=min(minn[i],atob(start,i));
//			f[i]=1;
//			time(i,end);
//			f[i]=0;
//		}
//	}
//	
//	
//}
//
//
//int main(){
//	
////	freopen("subway.in","r",stdin);
////	freopen("subway.out","w",stdout);
//	
//	
//	cin>>c>>n>>m>>d>>q;
//	for(int i=1;i<=m;i++)cin>>w[i];
//	for(int j=1;j<=n;j++){
//		cin>>k;
//		for(int i=1;i<=k;i++){
//			cin>>a[j][i]>>t[j][i];
//		}
//	}
////	for(int i=1;i<=q;i++){
////		cin>>x[i]>>y[i];
////	}
//
//	for(int i=1;i<=q;i++){
//		cin>>x>>y;
//		ans=w[x]+w[y];
//		time(x,y);
//		cout<<minn[y]+ans;
//		for(int j=0;j<=m;j++)minn[j]=0;
//	}
//	
////	ans=w[x]+w[y];
//	
//	
//	return 0;
//}
//
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数。
int w[500005];//表示从每个地铁站的地铁口走到站厅需要的时间
int k,a[505][5005],t[505][5005];
//int x[100005],y[100005];
int x,y;
int minn[500005];
bool f[500005];
int ans;

int a1,b1,tmp;

int find(int num,int zhan){
	for(int i=1;i<=n;i++){
		if(a[num][i]==zhan){
			
			return i;
		}
	}return 0;
}

int atob(int ax,int by){
	for(int i=1;i<=n;i++){
		a1=find(i,ax);
		b1=find(i,by);
		
		if(a1&&b1){
			tmp=t[i][a1]+t[i][b1];
			
			return tmp;
		}
	}return 10000000LL;
}



void time(int start,int end){
	
	for(int i=1;i<=m;i++){
		if(find(start,i)&&start!=i&&f[i]!=1){
			
			minn[i]=min(minn[i],atob(start,i));
			f[i]=1;
			time(i,end);
			f[i]=0;
		}
	}
	
	
}


int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int j=1;j<=n;j++){
		cin>>k;
		for(int i=1;i<=k;i++){
			cin>>a[j][i]>>t[j][i];
		}
	}
//	for(int i=1;i<=q;i++){
//		cin>>x[i]>>y[i];
//	}

	for(int i=1;i<=q;i++){
		cin>>x>>y;
		ans=w[x]+w[y];
		time(x,y);
		cout<<minn[y]+ans<<endl;
		for(int j=0;j<=m;j++)minn[j]=0;
	}
	
//	ans=w[x]+w[y];
	
	
	return 0;
}


