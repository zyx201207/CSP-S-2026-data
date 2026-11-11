#include<iostream>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;

long long nums[500010];
long long ans[300010];
long long posision[300010];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card1.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++){
		cin >> nums[i];
	}
	for (int str = 1; str <= n ; str++){
		int now = str;
		int crds[500010];
		int i=1;
		memset(crds,0,sizeof(crds));
		while(1){
			if(posision[nums[now]]!=0 ){
				for (int j = posision[nums[now]]+1 ; j <= i ; j ++){
					crds[j]=0;
				}
				i = posision[nums[now]];
			}else{
				crds[i] = nums[now];
				posision[crds[i]] = i;
			}
			if(now+1 > n){
				memset(posision,0,sizeof(posision));
				break;
			}
			now++;
			i++;
		}
		for (int j = 1 ; j <= i ; j ++){
			ans[crds[j]]++;
		}
	}
	for(int i = 1 ; i <= m ; i++){
		cout << ans[i] << " ";
	} 
	return  0;
}
