#include<bits/stdc++.h>
using namespace std;
int n,m;
int shu[500005],fen[300005],r[300005],gs[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>shu[i];
	for(int i=1;i<=n;i++){
		for(int y=i;y<=n;y++){
			if(fen[shu[y]]==1)for(int x=r[shu[y]];x<=y;x++)fen[shu[x]]=0;
			fen[shu[y]]++,r[shu[y]]=y;
		}
		for(int y=1;y<=m;y++){
			if(fen[y]==1)gs[y]++;
			fen[y]=0;
	    }
	}
	for(int i=1;i<=m;i++)cout<<gs[i]<<' ';
	return 0;
}