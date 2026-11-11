#include<bits/stdc++.h>
using namespace std;
int a[500010],cur[300010],cnt[300010],ans[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(cnt,0,sizeof(cnt));
		memset(cur,0,sizeof(cur)); 
		for(int j=i;j<=n;j++){
			cnt[a[j]]++;
			if(cnt[a[j]]==2){
				cnt[a[j]]=1;
				for(int k=cur[a[j]]+1;k<j;k++){
					cnt[a[k]]=0;
					cur[a[k]]=0;
				}
			}
			cur[a[j]]=j;
		}
		for(int j=1;j<=m;j++)
			if(cnt[j])
				ans[j]++;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	cout<<endl;
	return 0;
}
