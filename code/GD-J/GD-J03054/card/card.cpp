#include <bits/stdc++.h>
using namespace std;
constexpr int N=5e5+7;
int n,m,a[N],cnt[N];
vector<int> num;
int lst[N];
int ans[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n<=5000) {
		for(int i=1;i<=n;i++){
			num.clear();
			for(int j=1;j<=n;j++) lst[j]=-1;
			for(int j=i;j<=n;j++){
				if(lst[a[j]]==-1){
					num.push_back(a[j]);
					lst[a[j]]=num.size();
				}else{
					while((int)num.size()>=lst[a[j]]){
						num.pop_back();
					}
					num.push_back(a[j]);
				}
			}
			for(auto &it:num){
				ans[it]++;
			}
		}
		for(int i=1;i<=m;i++){
			printf("%d ",ans[i]);
		}
		return 0;
	}else{
		for(int i=1;i<=n;i++) ans[a[i]]=max(ans[a[i]],i);
		for(int i=1;i<=n;i++){
			num.push_back(a[i]);
			cnt[a[i]]++;
			if(cnt[a[i]]>=2){
				cnt[a[i]]--;
				num.pop_back();
				while((*num.rbegin())!=a[i]){
					cnt[*num.rbegin()]--;
					if(cnt[*num.rbegin()]==0) ans[a[*num.rbegin()]]--;
					num.pop_back();
				}
			}
		}
		for(int i=1;i<=m;i++){
			printf("%d ",ans[i]);
		}
		return 0;
	}
	return 0;
}

