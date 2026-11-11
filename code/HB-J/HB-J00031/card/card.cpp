#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],sum[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=500){
		for(int i=1;i<=n;i++){
			int book[300005]={0},bookk=1;
			for(int j=i;j<=n;j++){
				for(int s=1;s<bookk;s++){
					int k=0;
					if(book[s]==a[j]&&k==0){
						bookk=s;
						k=1;
					}
				}
				book[bookk]=a[j];
				bookk++;
			}
			for(int j=1;j<bookk;j++)
				sum[book[j]]++;
		}
		for(int i=1;i<=m;i++)cout<<sum[i]<<" ";
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=a[i];j<=a[n];j++){
				sum[j]++;
			}
		}
		for(int i=1;i<=m;i++)cout<<sum[i]<<" ";
	}
	return 0;
}
