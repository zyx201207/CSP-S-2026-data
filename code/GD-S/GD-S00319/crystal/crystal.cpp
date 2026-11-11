#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
const int INF=0x3f3f3f;
int n,m;
int a[N];
int maxx=-INF,ans=0,sa=0,sb=0;

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int w=0;
	for(int i=1;i<=n;i++){
		if(a[i]==i)sa++;
		if((a[i]-a[i-1]==a[i-1]-a[i-2])||(a[i]+a[i-1]==a[i-1]+a[i-2]))
			sb++;w=a[i]-a[i-1];
	}
	if(sa==n){
		if(n==m||n+1==m){
			cout<<n/2+1;
			return 0;
		}
		cout<<2;
	}
	else if(sb==n){
		if(n+w+1==m||n-w-1==m){
			cout<<3;
			return 0;
		}
		cout<<2;
	}
	else{
		int t;
		if(n%2==1)t=a[n/2+1];
		else t=a[n/2];
		for(int i=1;i<=n;i++){
			int x=t-a[i];
			if(x>0&&m>x&&a[i]<=t){
				ans++;
				m-=x;
			}
			else if(a[i]==t)ans++;
			if(m<=0)break;
		}
	}
	cout<<ans+1;
	return 0;
} 
