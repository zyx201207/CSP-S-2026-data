#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],last[300005],per,table[500005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){ 
		memset(table,0,sizeof(table));
		per=0;
		for(int j=i;j<=n;j++){
			if(last[a[j]]==0){
				table[++per]=a[j];
				last[a[j]]=j;
			}
			else while(table[per]!=a[j])per--;
		}
		for(int k=1;k<=per;k++){
			for(int j=1;j<=m;j++)if(j==table[k])ans[j]+=1;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
