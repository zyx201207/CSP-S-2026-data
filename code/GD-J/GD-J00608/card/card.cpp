#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e5+5;
int n,m;
int a[N],cs[N];
int early[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	for(int i = 1;i<=n;i++){
		int u=0;
		memset(early,0,sizeof(early));
		for(int j = i;j<=n;j++){
			if(early[a[j]]){
				int tt=early[a[j]];
				for(int k = 1;k<=m;k++){
					if(tt<early[a[k]]){
						early[a[k]]=0;
						u--;
					}
				}
				early[a[j]]=u+1;
				u++;
			}else{
				early[a[j]]=u+1;
				u++;
			}
		}
		for(int j = 1;j<=m;j++){
			if(early[a[j]]){
				cs[a[j]]++;
			}
		}
	}
	for(int i = 1;i<=m;i++){
		cout<<cs[i]<<" ";
	}
	return 0;
}

