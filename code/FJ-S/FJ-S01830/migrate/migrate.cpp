#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t;
struct inland{
	int x;
	int roads=0;
	int mi_ro;
	int dp;
}xx[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	int ans,n,d;
	srand(time(0));
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		int l12=0;
		int x=rand()%(n+1);
//		for(int j=1;j<=n;j++){
//			cin>>xx[j].x;
//			int mx;
//			for(int k=j;k>=1;k--){
//				if(xx[k].x<xx[j].x-d){
//					xx[j].mi_ro=xx[k+1].x;
//				}
//			}
//			if(xx[j].mi_ro==mx+xx[j].x){
//				xx[j].roads+=1;
//			}else{
//				xx[j].mi_ro=min(xx[j].mi_ro,mx+xx[j].x);
//			}
//			if(xx[j].roads==2){
//				l12++;
//				
//			}
//		}
		cout<<x<<endl;
	}
	return 0;
}
