#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long ans=1,n,m,a[N],pre[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]+a[i];
	}
	sort(a+1,a+1+n);
	for(long long j=1;j<=n;j++){
		for(long long len=2;j+len-1<=n;len++){
			long long i=j+len-1;
			long long m1=a[i]*(i-j)-(pre[i-1]-pre[j-1]);
			long long temp=0;
			for(int	k=j;k<i;k++)temp+=(a[i]-a[k]);
			if(temp<=m){
				ans=max(len,ans);
//				cout<<i<<" "<<j<<" "<<m1<<" "<<temp<<"\n"; 
			}
			else break;
		}
	}
	cout<<ans;
	return 0;
} 
//3845
