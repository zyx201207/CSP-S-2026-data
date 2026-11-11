#include<bits/stdc++.h>
using namespace std;
int n,m,a[500011],id[300011],tab[500011],cnt[500011];
void play(int ii){
	memset(id,127,sizeof(id));
	memset(tab,0,sizeof(tab));
	int wei=0;
	for(int i=ii;i<=n;i++){
		if(id[a[i]]>wei){
			id[a[i]]=(++wei);
			id[tab[wei]]=INT_MAX;
			tab[wei]=a[i];
		}
		else {wei=id[a[i]];tab[wei]=a[i];}
//		for(int j=1;j<=wei;j++) cout<<tab[j]<<"\t";
//		cout<<endl;
	}
	for(int i=1;i<=wei;i++)
		cnt[tab[i]]++;
}
int main(){
	freopen("card3.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		play(i);
	for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
	return 0;
}
/*
4 3
1 2 1 3
10 3
3 1 2 1 3 2 3 1 2 1
*/
