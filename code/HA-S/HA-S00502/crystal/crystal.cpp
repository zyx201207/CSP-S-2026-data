#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn=5e5+2;

int ans=1;
ll n,m,sum1=0,maxn1=1;
ll a[maxn],cha[maxn],qcha[maxn];
int b[100000000];

int main()
{
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		sum1+=a[n]-a[i];
	}
	for(int i=2;i<=n;i++)
	{
		cha[i]=a[i]-a[i-1];
		qcha[i]=qcha[i-1]+cha[i];
	}
	if(sum1<=m){
		cout << n << endl;
		return 0;
	}
//	cout << qcha[5] << endl;
	for(int i=1;i<=n;i++)
	{
		ll sum=0;
		for(int j=i-1;j>0;j--){
			sum+=qcha[i]-qcha[j];
//			cout << "i£º" << i << "sum£º" << sum << endl; 
			if(sum>m){
				ans=max(ans,i-j); 
				break;
			}
			else if(sum==m){
				ans=max(ans,i-j+1); 
				break;
			}
			ans=max(ans,i-j+1);
		}
	}
	cout << ans << endl;
	return 0;
}
