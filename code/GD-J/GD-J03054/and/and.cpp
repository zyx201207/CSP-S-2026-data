#include <bits/stdc++.h>
using namespace std;
int res;
constexpr int N=2e5+7;
int n,m,a[N];
vector<int> num,tmp;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		num.push_back(a[i]);
	}
	for(int i=30;i>=0;i--){
		tmp.clear();
		for(auto &it:num){
			if(it&(1<<i)){
				tmp.push_back(it);
			}
		}
		if((int)tmp.size()>=m){
			res|=(1<<i);
			num.swap(tmp);
		}
	}
	printf("%d\n",res);
	return 0;
}

