#include<bits/stdc++.h>
using namespace std;
queue<int> qu;
int m,n;
int maxx;
int a[210000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		maxx=a[1];
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
		return 0;
	}
	if(m==n){
		maxx==a[1];
		for(int i=1;i<=n;i++)
		{
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2)
	{
		ans==a[1]&a[2];
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
		return 0;
	}
	return 0;
}
