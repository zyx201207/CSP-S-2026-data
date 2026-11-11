#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],c[N][35],p[N];
long long ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<=30;j++){
			if((a[i]>>j)&1) c[i][j]=1;
		}
	}
	for(int j=30;j>=0;j--){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(c[i][j]==1&&p[i]) cnt++;
			else p[i]=0;
		}
		if(cnt<m) {
			if(ans==0) for(int i=1;i<=n;i++) p[i]=1;
		}
		else ans+=(1<<j);
	}
	//for(int i=1;i<=n;i++) if(p[i]) cout<<i<<" ";
	cout<<ans;
	//5 3 31 3 1 15 7
	//4 2 3 15 12 12
	return 0;
}
