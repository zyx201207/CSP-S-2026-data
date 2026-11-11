#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[300005],pos[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int r=1;r<=n;r++){
		vector<int> cards;
		for(int i=1;i<=m;i++)pos[i]=0;
		for(int i=r,now;i<=n;i++){
			now=a[i];
			if(pos[now]){
				while(cards.size()>=pos[now])cards.pop_back();
			}
			cards.push_back(now);
			pos[now]=cards.size();
		}
		for(int i=0;i<cards.size();i++)cnt[cards[i]]++;
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
	return 0;
}
