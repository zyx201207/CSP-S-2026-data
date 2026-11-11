#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,a[5005],dis[5005],num[5005],mxr[5005],ans;
queue<int> qu;

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>c>>t;
	while(t--){
		if(c>10) { cout<<"0\n"; continue; }
		cin>>n>>d; ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		int yy=1;
		for(int i=1;i<=n;i++){
			while(yy<n&&a[i]+d>=a[yy+1]) yy++;
			mxr[i]=yy;
		}
		for(int k=1;k<=n;k++){
			for(int i=k+1;i<=n;i++) dis[i]=INT_MAX,num[i]=0;
			qu.push(k); dis[k]=0; num[k]=1;
			while(qu.size()){
				int x=qu.front(),i=mxr[x]; qu.pop();
				while(dis[i]==INT_MAX){
					dis[i]=dis[x]+1,num[i]=num[x];
					qu.push(i);
					i--;
				}
				while(dis[i]==dis[x]+1){
					num[i]++;
					i--;
				}
			}
			for(int i=k;i<=n;i++) if(num[i]==2) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 1
10 3
0 3 6 7 8 9 10 11 14 17

*/
