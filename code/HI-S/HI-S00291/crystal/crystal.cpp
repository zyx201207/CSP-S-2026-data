#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500010];
bool cmp(int x,int y){
	if (x<y) return true;
	else return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	long long cnt=m;
	int num=0;
	for (int i=2;i<=n;i++)
	{
		cnt-=(i-1)*(a[i]-a[i-1]);
		if (cnt<0)
		{
			ans=i-1;
			num=a[i-1];
			break;
		}
		if (cnt==0)
		{
			ans=i;
			num=a[i];	
			break;
		} 		
	}
	for (int i=ans+1;i<=n;i++) if (a[i]==num) ans++;
	cout<<ans;
	return 0;
}
