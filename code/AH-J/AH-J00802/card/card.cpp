#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],cnt[300010],pos[300010],ans[300010],post[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		memset(cnt,0,sizeof(cnt));
		for(int i=k;i<=n;i++){
			if(cnt[a[i]]!=0){
				for(int j=pos[a[i]];j<i;j++){
					cnt[a[j]]--;
					pos[a[j]]=post[a[j]];
				}
				post[a[i]]=pos[a[i]];
				pos[a[i]]=i;
				cnt[a[i]]++;
			}
			else{
				cnt[a[i]]++;
				post[a[i]]=pos[a[i]];
				pos[a[i]]=i;
			}
		}
		for(int i=1;i<=m;i++){
			ans[i]+=cnt[i];
		}	
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
