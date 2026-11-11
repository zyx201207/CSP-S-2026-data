#include <bits/stdc++.h>
using namespace std;
int card[500005],pos[500005],pos2[500005],ans[500005],lin=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n;
	cin>>m>>n;
	for (int i=1;i<=m;i++){
		int y;cin>>y;
		card[lin++]=y;
	}for (int i=lin;i>0;i--){
		pos2[card[i]]=max(i,pos2[card[i]]);
		pos[i]=pos2[card[i]];
		
	}
	for (int i=1;i<=m;i++){
		for (int j=i;j<=lin;j++){
			ans[card[j]]++;
			j=pos[j];
		}
	}for (int i=1;i<=n;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
