#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,k;
	cin>>n>>m;
	int sum[m+5]={0},sum1[n+5]={0};
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
		
			cin >> k;
			for(int j=0;j<n;j++){
				int a=1,x;
				if(sum1[j]==k)
				{
					a=0;
					x=j;
					break;
				}
				if(a=0)
				{
					for(int i=x;i<=n;i++)
					{
						sum1[i]=0;
					}
				}
				sum1+=k; 
			}
			for(int i=1;i<=m;i++)
			{
				if(sum1[j]==i)
				{
					sum[i-1]+=1
				}
			}
		}
		
	}
	for(int i=0;i<=m;i++){
		cout << sum[i];
	}
	return 0;
}
