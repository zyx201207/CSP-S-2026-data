#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[5233],ans[3325];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[i+1])
			ans[a[i]]++;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]+1<<" ";
	return 0;
}
