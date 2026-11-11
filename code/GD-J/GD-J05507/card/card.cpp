#include<bits/stdc++.h>
using namespace std;
bool flag[300005];
int num[500005],ans[300005];
vector<int>cards;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a,b;
	cin>>a>>b;
	for(int u=1;u<=a;u++){
		cin>>num[u];
	}
	for(int i=1;i<=a;i++){
		for(int o=i;o<=a;o++){
			if(flag[num[o]]==1){
				for(int u=cards.size()-1;u>=0;u--){
					if(cards[u]==num[o]){
						for(int injj=cards.size()-u;injj>=1;injj--){
							flag[cards[u-injj+1]]=0;
						}
						for(int injj=1;injj<=cards.size()-u;injj++){
							cards.pop_back();
						}
						break;
					}
				}
			}
			cards.push_back(num[o]);
			flag[num[o]]=1;
		}
		for(int u=1;u<=b;u++){
			if(flag[u]==1){
				ans[u]++;
			}
		}
		memset(flag,0,sizeof(flag));
		cards.clear();
	}
	for(int u=1;u<=b;u++){
		cout<<ans[u]<<" ";
	}
	return 0;	
} 
