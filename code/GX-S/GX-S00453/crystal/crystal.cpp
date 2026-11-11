#include<bits/stdc++.h>
using namespace std;
long long a[1000000],vis[1000000],n,m,ans,anss;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("crystal2.in","r",stdin);
	freopen("crystal2.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,cmp);
	
	for(int j=1;j<=n;j++) vis[j]=a[j];
	long long nn=n;
	for(int i=1;i<=n;i++)
	{
		long long o=2;
		anss=1;
		long long mx=m;
		while(1)
		{
			if(mx-(vis[1]-vis[o])>=0 && o<=nn) mx-=(vis[1]-vis[o]),anss+=1,o+=1;
			else break;
		}
		ans=max(ans,anss);
		vis[1]=0;
		nn--;
		sort(vis+1,vis+1+n,cmp);
	}
	cout<<ans;
    return 0;
}
