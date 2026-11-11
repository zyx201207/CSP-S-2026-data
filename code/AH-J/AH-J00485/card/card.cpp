#include<bits/stdc++.h>
using namespace std;
int n,m;
int  card[500010];
int place[300010];
long long cnt[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>card[i];
	}
	for(int i=1;i<=n;i++){
		memset(place,0,sizeof(place));
		for(int j=i;j<=n;j++){
			if(place[card[j]]!=0){
				for(int k=place[card[j]];k<=j;k++){
					place[card[k]]=0;
				}
			}
			place[card[j]]=j;
		}
		for(int j=1;j<=m;j++){
			if(place[j]!=0)cnt[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
}
