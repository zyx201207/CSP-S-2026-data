#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=2e6+10;
int c,t;
int n,d;
int a[N],sum[N];
int ans=0,cnt;
void dfs(int minn,int k,int w,int wa){
	if(k==minn){
//		cout<<w<<endl;
		if(w==wa)ans++; 
		return;
	}
	if(w>n) return;
	for(int i=1;i<=n;i++){
		if(a[w+i]-a[w]<=d) dfs(minn,k+1,w+i,wa);
		else break;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cnt=0;
		cin>>n>>d;
		int gc;
		int flag=1;
		for(int i=1;i<=n;++i){
			cin>>a[i];
			if(i==2) gc=a[i]-a[i-1];
			else if(a[i]-a[i-1]!=gc) flag=0;
		}
		if(flag){
			d/=gc;
			cout<<(d>1?n-2*d+1:0)<<endl;
		}
		else{
			for(int i=1;i<=n;++i){
				for(int j=i+1;j<=n;++j){
					ans=0;
					int minn=0,i1=i;
					int l;
					for(l=i+1;l<=j;++l){
						if(a[l]-a[i1]>d){
							if(l==i1+1) break;
							i1=--l;
							minn++;
						}
					}
					minn++;
					if(minn>1&&l!=i1+1){
						dfs(minn,0,i,j);
					}
	//				cout<<ans<<endl;
					if(ans==2) cnt++;
				}
			}
			cout<<cnt<<endl;
		}
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
