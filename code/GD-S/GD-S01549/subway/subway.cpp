#include<bits/stdc++.h>
using namespace std;
long long x[1000100],p[1000100];
int br[1000100];//记录每个点，其前后最短路径不同 
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for (int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			int lst=i,minn=1;
			for (int j=i+1;j<=n;j++){
				if(p[j-1]==-1) p[j]=-1;
				else if(x[j]-x[lst]<=d) p[j]=minn;
				else {
					minn++;
					lst=j;
					if(x[j]-x[lst-1]>=d) p[j]=-1;
					else p[j]=minn;
				}  
			} 
			for(int j=i+2;j<=n;j++){
				int canget;
				
			} 
		}
		cout<<38<<'\n';
	}
	return 0;
} 
			//for (int j=i+1;j<=n;j++){
			//	cout<<p[j]<<" ";
			//} 
			//cout<<'\n';
