#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int k[505];
int a[505][505];
//int jilu[500005];
int t[505][505];
int w[50005];
//int jiao[50005];
//bool a1[50005][50005];
int qidian[505],zhongdian[505];
ll c,m,n,d,q;
//int search(int x1,int y1){
	//int i=1,tz=0;
	//while(jilu[i]!=y1){
		//for(int j=1; j<=50005; i++){
			//if(a1[jilu[i]][a[i][j]]==1){
				//jilu[i]=a[i][j];
				//tz+=t[i][j];
			//}
		//}
		//i++;
	//}
	//return tz;
//}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int v=1; v<=m; v++){
		cin>>w[v];
	}
	for(int i=1; i<=n; i++){
		cin>>k[i];
		for(int j=1; j<=2*k[i]; j++){
			cin>>a[i][j]>>t[i][j];
			//a1[a[i][j]][a[i][j-1]]=1;
		}
	}
	int xr,yr,bhq=1,bhz=1;
	for(int i=1; i<=q; i++){
		cin>>xr>>yr;
		for(int j=1; j<=n; j++){
			for(int l=1; l<=2*k[i]; l++){
				if(a[j][l]==xr){
					qidian[bhq]=a[j][l];
					bhq++;
				}
				if(a[j][l]==yr){
					zhongdian[bhz]=a[j][l];
					bhz++;
				}
			}
		}
		int ans=0,minn=500005;
		for(int j=1; j<=bhq; j++){
			for(int k=1; k<=qidian[j]; k++){
				for(int l=1; l<=n; l++){
					ans+=t[k][l];
				}
			}
			minn=min(ans,minn);
		}
		//for(int i=1; i<=bhq; i++){
			//for(int j=1; j<=bhz; j++){
				//ans=max(search(qidian[i],zhongdian[j]),ans);
			//}
		//}
		cout<<minn+w[xr]+w[yr]<<endl;
	}
	return 0;
}
