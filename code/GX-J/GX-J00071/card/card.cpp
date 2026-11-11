#include<bits/stdc++.h>
using namespace std;
int a[500005];
int v[500005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int id=0;
	for(int i=1;i<=n;i++)
	{
		
		cin>>a[i];
		if(a[i]!=a[i-1] && i-1>0)id=i-1;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<n;j++){
			if(a[j]!=a[j-1] && j-1>0)
			{
				if((j-1-id)%2==1)v[a[j-1]]++,id=j;
			}
		
		}
	}
	for(int i=1;i<=m;i++)cout<<v[i]<<" ";


	return 0;
}
