#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],cnt[300005],res[300005],ans[300005];
vector<int> pos[300005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;//剩余 
		res[a[i]]++;//总共 
		pos[a[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		int now=a[i];//当前卡牌 
		int p=res[a[i]]-cnt[a[i]]+1;//当前卡牌为第几个同编号卡牌 
		int k=i;//当前位置 
		while(k<=n){
			if(p==res[a[k]]){
				//cout<<k<<" "<<p<<" "<<now<<"\n";
				ans[a[k]]++;
				k++;
				p=res[a[k]]-cnt[a[k]]+1;
				now=a[k];
				continue; 
			}
			p++;
			k=pos[a[k]][p-1];
		}
		cnt[a[i]]--;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
