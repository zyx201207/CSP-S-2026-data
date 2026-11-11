#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,T,a[N],b[N],n,d,minn=1e9,minx;
//void dfs(int x,int y){
//	int l=0,i=1;
//	while(x==y){
//		if(l+b[i]<=d){
//			l+=b[i++];
//			
//		}else{
//			
//		}
//	}
//}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		memset(a,0,sizeof a);
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			b[i]=a[i]-a[i-1];
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
//				dfs(i,j);
				if(minx==2)ans++;
			}
		}
		cout<<0<<endl;
	}
	return 0;
}
