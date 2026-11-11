#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","out",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
    for(int i=1;i<=m;i++)
    {
    	int ans=0;
    	for(int j=0;j<n;j++)
    	{
    		if(a[j]==m) ans++;
		}
		if(ans%2==0) cout<<ans/2<<' ';
		else cout<<(ans+1)/2<<' ';
	}
	return 0;
}
