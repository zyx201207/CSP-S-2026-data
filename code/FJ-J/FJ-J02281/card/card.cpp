#include<bits/stdc++.h>
using namespace std;
int a[604800],cnt[604800],p[604800],ans[604800];
int n,m;
void top(){
	for(int i=1;i<=m;i++)cnt[i]=0,p[i]=0;
	for(int i=m;i<=n;i++)p[i]=0;
} 
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			cnt[a[j]]++;
			p[j]=a[j];
			if(cnt[a[j]]==2){
				int l=j-1;
				while(1){
					cnt[l--]--;
					if(p[l]==a[j]){
						break;
					}
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(cnt[j])ans[j]++;
		}
		top();
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
