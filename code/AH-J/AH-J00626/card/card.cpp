#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,a[100000],k,ans[10000],pos[100000],cnt[100000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(cnt,0,sizeof cnt);
		memset(pos,0,sizeof pos);
		for(int j=i;j<=n;j++){
			if(cnt[a[j]]){
				cnt[a[j]]=0;
				for(int p=pos[a[j]];p<=j;p++)cnt[a[p]]=0;
			}
			cnt[a[j]]++;
			pos[a[j]]=j;
		}
		for(int j=1;j<=m;j++)ans[j]+=cnt[j];
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
