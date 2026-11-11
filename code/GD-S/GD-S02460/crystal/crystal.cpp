#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=b;i++)
#define D(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
using namespace std;const int N=5e5+67;
int n,m,ans;ll a[N],sum,cnt;bool f=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	F(i,1,n){
		cin>>a[i];
		if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2])f=1;
	}sort(a+1,a+n+1);
	int l=n-1,r=n;
	if(f==0){
		while(l>0&&r>l){
			sum+=a[r]-a[l];
			if(sum>m){cout<<r-l;return 0;}
			l--;
		}cout<<n;
		return 0;
	}while(l>0&&r>l){
		sum+=a[r]-a[l],cnt++;
		while(sum>m&&sum-cnt*(a[r]-a[r-1])>=0&&l>0&&r>l&&cnt>=0){
			sum-=cnt*(a[r]-a[r-1]);
			r--,cnt--;
		}ans=max(ans,r-l+1);
		l--;
	}cout<<ans;
	return 0;
}
