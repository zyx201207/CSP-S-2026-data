#include<bits/stdc++.h>
#define itn int
using namespace std;
const int N=2e5+10;
int a[N];
bool b[31][N],vis[N],ans[N],dis[N];
int n,m;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int len=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int x=a[i];
		itn cnt=0;
		while(x){
			int y=1;
			b[cnt][i]=(y&x);
			x>>=1;
			cnt++;
			len=max(cnt,len);
		}
	} 
	/*for(itn i=1;i<=n;i++){
		for(int j=0;j<len;j++){
			cout<<b[j][i]<<' ';
		}
		cout<<endl;
	}
	*/
	bool ok=0;
	for(int i=len-1;i>=0;i--){
		itn cnt=0;
		for(int j=1;j<=n;j++){
			if(b[i][j]&&(!ok||vis[j])){
				cnt++;
				dis[j]=1;
			}
		}
		if(cnt>=m){
			ok=1;
			ans[i]=1;
			for(int i=1;i<=n;i++){
				if(!dis[i]){
					vis[i]=0;
				}else{
					vis[i]=1;
				}
				dis[i]=0;
			}
		}
	}
	itn res=0;
	for(int i=0;i<=n;i++){
		res+=(ans[i]<<i);
	}
	cout<<res;
	return 0;
} 
