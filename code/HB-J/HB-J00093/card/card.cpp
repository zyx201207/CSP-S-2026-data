#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],last[300005],ans[300005];
bool on_table[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(on_table,1,sizeof on_table);
		memset(last,0,sizeof last);
		for(int j=i;j<=n;j++){
			if(last[a[j]]&&on_table[last[a[j]]]){
				for(int k=last[a[j]];k<j;k++)on_table[k]=0;
			}
			last[a[j]]=j;
		}
		for(int j=1;j<=m;j++){
			if(on_table[last[j]]&&last[j]!=0)ans[j]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
//But I am not new bee,I can not solve this problem.
