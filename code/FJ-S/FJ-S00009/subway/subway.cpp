#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+10;
int c,n,m,d,q,w[N],k,x,y,ans;
struct node{
	int a,t;
}l[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>l[i][j].a>>l[i][j].t;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		ans=w[x]+w[y];
		int flag=1;
		for(int j=1;j<=k;j++){
			if(l[1][j-1].a==y){
				flag=0;
				break;
			}
			if(flag==0) break;
			ans+=l[1][j].t;
		}	
		cout<<ans<<endl;
//		if(n==2){
//			int z1=0,zz1=0,z2=0,zz2=0;
//			for(int j=1;j<=k;j++){
//				if(l[1][j].a==x){
//					z1++;
//				}
//				if(l[1][j].a==y){
//					zz1++;
//				}
//			}
//			for(int j=1;j<=k;j++){
//				if(l[2][j].a==x){
//					z2++;
//				}
//				if(l[2][j].a==y){
//					zz2++;
//				}
//			}
////			cout<<z1<<" "<<zz1<<" "<<z2<<" "<<zz2<<endl;
//			if(z1==1&&zz1==1){
//				int flag=1;
//				for(int j=1;j<=k;j++){
//					if(l[1][j-1].a==y){
//						flag=0;
//						break;
//					}
//					if(flag==0) break;
//					ans+=l[1][j].t;
//				}
//				cout<<ans<<endl;
//				return 0;
//			}
//			if(z2==1&&zz2==1){
//				int flag=1;
//				for(int j=1;j<=k;j++){
//					if(l[2][j-1].a==y){
//						flag=0;
//						break;
//					}
//					if(flag==0) break;
//					ans+=l[2][j].t;
//				}
//				cout<<ans<<endl;
//				return 0;
//			}
//			if(z1==1&&zz2==1){
//				int flag=1;
//				for(int j=1;j<=k;j++){
//					if(l[1][j-1].a==x){
//						flag=0;
//						break;
//					}
//					if(flag==0) break;	
//					ans+=l[1][j].t;
//				}
//				flag=1;
//				for(int j=1;j<=k;j++){
//					if(l[2][j-1].a==y){
//						flag=0;
//						break;
//					}
//					if(flag==0) break;	
//					ans+=l[2][j].t;
//				}
//				cout<<ans<<endl;
//				return 0;
//			}
//			if(z2==1&&zz1==1){
//				int flag=1;
//				for(int j=1;j<=k;j++){
//					if(l[2][j-1].a==x){
//						flag=0;
//						break;
//					}
//					if(flag==0) break;	
//					ans+=l[2][j].t;
//				}
//				flag=1;
//				for(int j=1;j<=k;j++){
//					if(l[1][j-1].a==y){
//						flag=0;
//						break;
//					}
//					if(flag==0) break;	
//					ans+=l[1][j].t;
//				}
//				cout<<ans<<endl;
//				return 0;
//			}
	}
	return 0;
}

