#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int num[500005];
int ans[500005]={0};
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			num[j]=a[j];
			if(j>i){
				if(num[j]==num[j-1]){
					num[j]=0,num[j-1]=0;
				}
			}
		}
		for(int j=1;j<=n;j++){
			ans[num[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
