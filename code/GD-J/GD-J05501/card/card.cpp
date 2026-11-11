#include <bits/stdc++.h>
using namespace std;
map<int,int> cnt;
int cards[500010];
vector<int> desk;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&cards[i]);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int flag=0,_;
			for(int k=0;k<desk.size();k++){
				if(desk[k]==cards[j]){
					flag=1,_=k;
					break;
				}
			}
			if(flag){
				for(int k=_;k<=desk.size();k++)
					desk.erase(desk.begin()+k);
				}
			desk.push_back(cards[j]);
		}
		for(int j=0;j<desk.size();j++){
			cnt[desk[j]]++;
		}
	}
	for(auto it:cnt){
		printf("%d ",it.second);
	}
	return 0;
}
