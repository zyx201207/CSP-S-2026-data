#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m;
const int N=5e5;
long long a[N+1];
bool check(){
	for(int i=3;i<=n;i++)
	{
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]) return false;
	}
	return true;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);//¶Ôa[i]½øÐÐÅÅÐò 

	int ans=1;
	if(check())
	{
		for(int i=1;i<=n;i++)
		{
			if(m>=((long long )n*(long long )n+1/2*(a[2]-a[1])))
			{
				ans=max(ans,i);
			}
			else break;
		}
	}
	else {
		int cnt=1;
		
		for(int i=2;i<=n;i++)
		{
			while(m<(i-cnt)*(a[i]-a[i-1]))
			{
				m+=a[i-1]-a[cnt];
				cnt++;
			}
			if(m>=(i-cnt)*(a[i]-a[i+1]))
			{
				ans=max(ans,i-cnt+1);
			}
		}
	} 
	cout<<ans<<'\n';
	//fclose(stdin);
    //fclose(stdout);
	return 0;
}//10 7
//1 2 3 4 5 6 7 8 9 10
//10 14
//2 4 6 8 10 12 14
