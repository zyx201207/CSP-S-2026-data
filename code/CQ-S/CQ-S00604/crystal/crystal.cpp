#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n; ll m,tot,a[N],c[N],sum[N];
bool check(){
	for(int i=1;i<n-1;i++)if(c[i]>=c[i+1])return 0;
	return 1;
}int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)c[i]=a[i+1]-a[i],tot+=c[i]*i;
	if(check()){
		for(int i=1;i<n;i++)sum[i]=sum[i-1]+c[i];
		int x=1,y=n-1; bool flag=0;
		while(!flag&&x<=y){
			if(tot<=m)break;
			int Y=c[y]*(y-x+1),X=sum[y]-sum[x-1];
			if(X<=Y)y--,tot-=Y; else x++,tot-=X;
		}if(x>y)return cout<<"0\n",0;
		cout<<y-x+2<<"\n";
	}else{
		int ans=n-1; bool flag=0;
		while(!flag){
			ll res=1e18;
			for(int i=1;i<=n-ans;i++){
				ll tmp=0,cnt=0;
				for(int j=i;j<=i+ans-1;j++)tmp+=c[j]*(++cnt);
				if(tmp<=m)return cout<<ans+1<<"\n",0;
			}ans--;
		}cout<<ans+1<<"\n";
	}
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
