#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n,m,a[N],mn[N],tjs[N],dqw[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(dqw,0,sizeof(dqw));
		memset(mn,0,sizeof(mn));
		int bl=1;
		for(int j=i;j<=n;j++){
			if(dqw[a[j]]==0){dqw[a[j]]=bl;mn[bl]=a[j];bl++;}
			else{bl--;int k=dqw[a[j]];
				for(;bl>=k;bl--){
					dqw[mn[bl]]=0;
					mn[bl]=0;
				}bl++;dqw[a[j]]=bl;mn[bl]=a[j];bl++;
			}
		}
		for(int j=1;j<bl;j++){tjs[mn[j]]++;}
	}for(int i=1;i<=m;i++){
		cout<<tjs[i]<<" ";
	}
	return 0;}
