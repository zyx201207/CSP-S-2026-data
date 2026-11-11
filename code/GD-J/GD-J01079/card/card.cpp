#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m,pos[M],a[N],b[M],ans[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int t=1;t<=n;t++){
		int l=0;
		memset(pos,-1,sizeof(pos));
		memset(b,0,sizeof(b));
		for(int i=t;i<=n;i++){
			if(pos[a[i]]==-1){
				pos[a[i]]=++l;
				b[l]=a[i];
			}else{
				for(int j=pos[a[i]]+1;j<=l;j++){
					pos[b[j]]=-1;
				}
				l=pos[a[i]];
			}
		}
		for(int i=1;i<=l;i++){
			ans[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/

