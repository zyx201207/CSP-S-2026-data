#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=32;
int n,m,ans,a[N][M];
bool pd[N];
void fj(int i,int x){
	int cnt=0;
	while(x){
		a[i][cnt]=x%2;
		x>>=1;
		cnt++;
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int x;
	for(int i=1;i<=n;i++) scanf("%d",&x),fj(i,x);
	for(int j=1;j<=n;j++) pd[j]=true;
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++) if(pd[j]) cnt+=a[j][i];
		if(cnt>=m){
			ans+=(1<<i);
			for(int j=1;j<=n;j++) if(!a[j][i]) pd[j]=false;
		}
	}
	cout<<ans<<endl;
	return 0;
}
