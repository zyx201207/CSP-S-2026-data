#include<bits/stdc++.h>
using namespace std;
int n,m,a[500500],ans[500500];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;){
			bool flag=false;
			for(int k=j+1;k<=n;k++){
				if(a[j]==a[k]){
					j=k;
					flag=true;
					break;
				}
			}
			if(!flag)ans[a[j++]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
