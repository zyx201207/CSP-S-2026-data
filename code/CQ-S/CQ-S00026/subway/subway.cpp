#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[500001];
int a[501][50001],t[501][50001];
int k[500001]; 
int to[50001];
int qw[500001];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){//第i个地铁口到对应站厅的时间 
		cin>>w[i];
	} 
	for(int i=1;i<=n;i++){
		cin>>k[i];//第i号线 
		for(int j=1;j<=k[i];j++){//第i个地铁站厅到第 i 条线站台的时间 
			cin>>a[i][j]>>t[i][j];//第i条线经过第j个站 
		}
	}
	int tim;//记录总时间 
	while(q--){
		tim=0;
		int x,y;
		cin>>x>>y;
		int f=0,fl=0,xk,yk,l=0,xi,yi,xkz,ykz;
		for(int i=1;i<=m;i++)to[i]=0;
		for(int i=1;i<=n;i++){
			
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==x){//找到起点 
					xkz=k[i];
					xk=j;
					xi=i;
				}
				if(a[i][j]==y){//找到终点 
					ykz=k[i];
					yk=j;
					yi=i;
				}
			}
		}
			
		
			for(int i=1;i<=n;i++){
			//不计换乘时间，计算起点和终点处耗费时间 
				
				
				
				for(int j=1;j<=k[i];j++){
					if(a[i][j]==x&&f==0){
						f=1;
						tim+=w[a[i][j]]+t[i][j];
						
					}
					else if(a[i][j]==y&&fl==0){
						tim+=t[i][j]+w[a[i][j]];
						
						fl=1;
					}
				}
	
			}
		
		if(xk!=yk){//换乘的情况 
			for(int i=1;i<=n;i++){
				for(int j=1;j<=k[i];j++){
					to[a[i][j]]++;
				} 
			}
			int cnt=0,minn=1e9;
			for(int j=1;j<=m;j++){
				if(to[j]>1){
					qw[++l]=to[j];
					
					
				}
			}
			int hcx,hcy;
			int hcx1,hcy1;
			for(int fw=1;fw<=l;fw++){
				for(int i=1;i<=xkz;i++){
					if(a[xi][i]==qw[fw]){
						hcx=i;
					}
				}
				for(int i=1;i<=ykz;i++){
					if(a[yi][i]==qw[fw]){
						hcy=i;
					}
				}
				cnt=0;
				cnt=cnt+t[xi][hcx]+t[yi][hcy];
				
				minn=min(cnt,minn);
			}
			tim+=minn;
		}	
		
		cout<<tim<<endl;
	}
	
	
	return 0;
}



//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2

//0 3 7 20 2
//8 3 6 1 7 2 9
//3 1 4 2 5 5 100
//3 2 6 3 1 7 2
//4 3 2 5 100 4 6 6 7
//1 6
//2 3

//#include <bits/stdc++.h>
//#define int long long
//using namespace std;
//int c,n,m,d,q;
//int w[500001];
//int a[501][50001],t[501][50001];
//int k[500001]; 
//int to[50001];
//int qw[500001];
//int xk[500001],yk[500001],xkz[500001],ykz[500001];
//int xi[500001],yi[500001];
//signed main()
//{
////	freopen("","r",stdin);
////	freopen("","w",stdout);
//	cin>>c>>n>>m>>d>>q;
//	for(int i=1;i<=m;i++){//第i个地铁口到对应站厅的时间 
//		cin>>w[i];
//	} 
//	for(int i=1;i<=n;i++){
//		cin>>k[i];//第i号线 
//		for(int j=1;j<=k[i];j++){//第i个地铁站厅到第 i 条线站台的时间 
//			cin>>a[i][j]>>t[i][j];//第i条线经过第j个站 
//		}
//	}
//	int tim;//记录总时间 
//	while(q--){
//		tim=0;
//		int x,y;
//		cin>>x>>y;
//		int f=0,fl=0,l=0,xkl=0,ykl=0;
//		for(int i=1;i<=m;i++)to[i]=0;
//		
//		for(int i=1;i<=n;i++){
//			
//			for(int j=1;j<=k[i];j++){
//				if(a[i][j]==x){//找到起点 
//					xkz[xkl++]=k[i];
//					xk[xkl]=j;
//					xi[xkl]=i;
//				}
//				if(a[i][j]==y){//找到终点 
//					ykz[ykl++]=k[i];
//					yk[ykl++]=j;
//					yi[ykl++]=i;
//				}
//			}
//		}
//		for(int i=1;i<=xkl;i++)xi[i]=0;
//		for(int i=1;i<=ykl;i++)yi[i]=0;
//		for(int i=1;i<=xkl;i++)xkz[i]=0;
//		for(int i=1;i<=ykl;i++)ykz[i]=0;
//		for(int i=1;i<=xkl;i++)xk[i]=0;
//		for(int i=1;i<=ykl;i++)yk[i]=0;	
//		
//			for(int i=1;i<=n;i++){
//			//不计换乘时间，计算起点和终点处耗费时间 
//				
//				
//				
//				for(int j=1;j<=k[i];j++){
//					if(a[i][j]==x&&f==0){
//						f=1;
//						tim+=w[a[i][j]]+t[i][j];
//						
//					}
//					else if(a[i][j]==y&&fl==0){
//						tim+=t[i][j]+w[a[i][j]];
//						
//						fl=1;
//					}
//				}
//	
//			}
//		
//		if(xk!=yk){//换乘的情况 
//			for(int i=1;i<=n;i++){
//				for(int j=1;j<=k[i];j++){
//					to[a[i][j]]++;
//				} 
//			}
//			int cnt=0,minx=1e9,miny=1e9;
//			for(int j=1;j<=m;j++){
//				if(to[j]>1){
//					qw[++l]=to[j];
//					
//					
//				}
//			}
//			int hcx,hcy;
//			int hcx1,hcy1;
//			for(int fw=1;fw<=l;fw++){
//				for(int ki=1;ki<=xkl;ki++){
//					for(int i=1;i<=xkz[ki];i++){
//					
//						if(a[xi[ki]][i]==qw[fw]){
//							hcx=i;
//						}
//					}
//					minx=min(minx,t[xi[ki]][hcx]);
//				}for(int ki=1;ki<=ykl;ki++){
//					for(int i=1;i<=ykz[ki];i++){
//					
//						if(a[yi[ki]][i]==qw[fw]){
//							hcy=i;
//							
//						}
//					}
//					
//					miny=min(miny,t[yi[ki]][hcy]);
//				}
//				
//				
//			}
//			tim+=minx+miny;
//		}	
//		
//		cout<<tim;
//	}
//	
//	
//	return 0;
//}

