#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,a[N],l[N],dp[N];
int ans=0;
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	a[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		l[i]=a[i]-a[i-1];
//		r[i-1]=a[i]-a[i-1];
	}
//	r[n]=INT_MAX;
	sort(a+1,a+n+1);
	int sum=0,ma=INT_MIN,m1,l,r;
	for(int i=1;i<=n;i++){
		sum=0;
		m1=0;
		int j=i;
		while(abs(sum)<=m&&j<=n){
			ma=max(m1,ma);
			sum=sum+abs(a[j]-a[j-1]);
			m1++;
			cout<<i<<' '<<j<<' '<<m1<<' '<<sum<<endl;
			j++;
		}
	}
	cout<<ma;
	return 0;
}
