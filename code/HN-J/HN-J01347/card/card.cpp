#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int ans[300005];
bool no[300005];
bool f[300005];
int first[300005],xian[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		no[a[i]]=1;
	}
	for(int i=1;i<=n;i++){
		int top=0;
		memset(f,0,sizeof(f));
		memset(first,0,sizeof(first));
		memset(xian,0,sizeof(xian));
		for(int j=i;j<=n;j++){
			if(f[a[j]]==0){
				xian[++top]=a[j];
				first[a[j]]=top;
				f[a[j]]=1;
			}
			else{
				int y=top;
				for(int k=first[a[j]];k<=y;k++){
					top--;
					first[xian[k]]=0;
					f[xian[k]]=0;
				}
				xian[++top]=a[j];
				first[a[j]]=top;
				f[a[j]]=1;
			}
		}
		for(int j=1;j<=top;j++){
			ans[xian[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		if(no[i]==1){
			cout<<ans[i]<<" ";
		}
	}
	return 0;
}
