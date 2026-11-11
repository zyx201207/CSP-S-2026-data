#include <bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[300010];
struct xbx{
	bool used=0;
	int id;
}cnt[500010];
void sol(int t){
	for(int i=t;i<=n;i++){
		if(cnt[a[i]].used==0){
			cnt[a[i]].used=1;
			cnt[a[i]].id=i;
		}
		else{
			for(int j=cnt[a[i]].id+1;j<i;j++){
				cnt[a[j]].used=0;
				cnt[a[j]].id=0;
			}
			cnt[a[i]].id=i;
		}
	}
	for(int i=1;i<=m;i++){
		if(cnt[i].used==1){
			ans[i]++;
		}
		cnt[i].used=0;
		cnt[i].id=0;	
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		sol(i);
	} 
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
