#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ans;
const int N=5e5+10;
int w[N],a[200][N],t[200][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}for(int i=1;i<=n;i++){
		int p;
		cin>>p;
		for(int j=1;j<=p;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}while(q--){
		int start,end;
		cin>>start>>end;
		ans=0;
		/*for(int i=1;i<=n;i++){
			for(int j=1;;j++){
				if(!a[i][j]) break;
				if(a[i])
			}
		}*/
		ans+=w[start]+w[end];
		//cout<<"ans:"<<ans<<endl;
		int startflag=0,endflag=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;;j++){
				if(!a[i][j]||(startflag&&endflag)) break;
				if(a[i][j]==start){
					ans+=t[i][j];
					startflag=1;
				}if(a[i][j]==end){
					ans+=t[i][j];
					endflag=1;
				}
			}
		}cout<<ans<<'\n';
	}
	return 0;
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
