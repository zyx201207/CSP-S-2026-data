#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long arr[5005][5005];//linjiebiao
struct node{
	long long a,cost;
}lines[600][5005];
long long in[500005];//入站时间 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(arr,0xffff,sizeof(arr));
	cin >>c >>n >>m >>d >>q;
	for(int i=1;i<=m;i++)cin >>in[i];
	
	for(int i=1;i<=n;i++){
		long long k;cin >>k;
		for(int j=1;j<=k;j++){
			cin >>lines[i][j].a >>lines[i][j].cost;
		}//输入一条线 
		for(int j=1;j<k;j++){
			for(int l=j+1;l<=k;l++){
				arr[lines[i][j].a][lines[i][l].a]=min((arr[lines[i][j].a][lines[i][l].a]),(lines[i][j].cost+lines[i][l].cost));
				//路径长即通勤时间
				arr[lines[i][l].a][lines[i][j].a]=arr[lines[i][j].a][lines[i][l].a];
				 
			}
		}
	}
	for(int i=1;i<=n;i++){//meitiaoxian
		for(int j=1;j<=n;j++){
			for(int l=1;l<=n;l++){
				arr[i][j]=min((arr[i][l]+arr[j][l]),arr[i][j]);
			}
		}
	}
	while(q--){
		long long x,y;cin >>x >>y;
		cout <<arr[x][y]+in[x]+in[y] <<'\n';
	}
}
//
//
//#include <bits/stdc++.h>
//using namespace std;
//long long c,n,m,d,q;
//long long arr[5005][5005];//linjiebiao
//struct node{
//	long long a,cost;
//}lines[600][5005];
//long long in[500005];//入站时间 
//int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	memset(arr,0xffff,sizeof(arr));
//	cin >>c >>n >>m >>d >>q;
//	for(int i=1;i<=m;i++)cin >>in[i];
//	
//	for(int i=1;i<=n;i++){
//		long long k;cin >>k;
//		for(int j=1;j<=2;j++){
//			cin >>lines[i][j].a >>lines[i][j].cost;
//		}//输入一条线 
//		arr[lines[i][1].a][lines[i][2].a]=min((arr[lines[1][i].a][lines[2][i].a]),(min((arr[lines[i][1].a][lines[i][2].a]),(lines[i][2].cost+lines[i][1].cost))));
//		arr[lines[1][i].a][lines[2][i].a]=arr[lines[i][1].a][lines[i][2].a];
//	}
//	for(int i=1;i<=n;i++){//meitiaoxian
//		for(int j=1;j<=n;j++){
//			for(int l=1;l<=n;l++){
//				arr[i][j]=min((arr[i][l]+arr[j][l]),arr[i][j]);
//			}
//		}
//	}
//	while(q--){
//		long long x,y;cin >>x >>y;
//		cout <<arr[x][y]+in[x]+in[y] <<'\n';
//	}
//}
