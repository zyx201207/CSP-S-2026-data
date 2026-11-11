#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int lst[300005];
int ans[300005];
bool now[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) lst[j]=-1;
		memset(now,0,sizeof now);
		for(int j=i;j<=n;j++){
			if(lst[a[j]]!=-1){
				for(int k=lst[a[j]];k<j;k++){
					now[a[k]]=0;
					lst[a[k]]=-1;
				}
				now[a[j]]=1;
				lst[a[j]]=j;
			}else{
				now[a[j]]=1;
				lst[a[j]]=j;
			}
		}
		for(int j=1;j<=m;j++){
			if(now[j]==1) ans[j]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}
