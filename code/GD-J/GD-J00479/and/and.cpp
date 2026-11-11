#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans;
int bit[N][32];
int is[N],f;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=31;j>=0;j--){
			if((a[i]>>j)&1) bit[i][j]=1;
		}
	}
/*	for(int i=1;i<=n;i++){
		for(int j=0;j<=3;j++){
			if(bit[i][j]) cout<<j<<" "; 
		}
		cout<<'\n';
	}*/
	
	for(int now=31;now>=0;now--){
		int cnt=0;
		if(f==0){
			for(int i=1;i<=n;i++){
				if(bit[i][now]){
					cnt++;
				}
			}
			if(cnt>=m){
				f=1;	
				for(int i=1;i<=n;i++){
					if(bit[i][now]){
						is[i]=1;
					}
				}
				ans=1<<now;
			}
			continue;
		}
		for(int i=1;i<=n;i++){
			if(bit[i][now]&&is[i]){
				cnt++;
			}
		}
		if(cnt>=m){
			ans|=1<<now;
			for(int i=1;i<=n;i++){
				if(is[i]&&!bit[i][now]) is[i]=0;
			}
		}
	}
	cout<<ans;
	return 0;
} 
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
