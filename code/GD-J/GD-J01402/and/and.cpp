#include<bits/stdc++.h>
using namespace std;

const int maxn=5e5+100;
int n,m;
long long a[maxn];
int l[maxn];
bool ex[maxn][35],ans[35],vis[maxn];
int len[maxn];
long long qp[35];
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	qp[0]=1;
	for(int i=1;i<=33;i++){
		qp[i]=qp[i-1]*2;
	}
	cin>>n>>m;
	memset(l,0,sizeof(l));
	memset(len,0,sizeof(len));
	memset(ans,false,sizeof(ans));
	memset(vis,true,sizeof(vis));
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int k=1;
		while(a[i]!=0){
			if(a[i]%2==1){
				ex[i][k]=1;
				l[k]++;
			}else{
				ex[i][k]=0;
			}
			a[i]/=2;
			len[i]++;
			k++;
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=len[i];j++){
//			cout<<ex[i][j];
//		}
//		cout<<endl;
//	}
	int i=31;
	while(i>=1){
		if(l[i]>=m){
			ans[i]=1;

			for(int j=1;j<=n;j++){
				if(ex[j][i]==0){
					vis[j]=false;
				}

				if(!vis[j]&&ex[j][i-1]==1){
					vis[j]=false;
					l[i-1]--;
				}
			}
		}else{
			for(int j=1;j<=n;j++){
				if(!vis[j]&&ex[j][i-1]==1){
					vis[j]=false;
					l[i-1]--;
				}
			}
		}	
		
		i--;
	}
	long long t=0;
	for(int i=1;i<=31;i++){
		t+=ans[i]*qp[i-1];
	}
//	cout<<l[2];
	cout<<t;
	return 0;
}
/*4 2
  3 15 12 12
*/ 
