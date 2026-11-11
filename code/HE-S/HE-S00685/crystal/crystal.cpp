#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define ll long long
#define fori(a,b) for(int i=a;i<=b;i++)
#define forj(a,b) for(int j=a;j<=b;j++)
using namespace std;
int n,m,a[500050],ans=1,c[500050];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	fori(1,n){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	fori(1,n){
		int k=m;
		bool ok=1;
		forj(i+1,n){
			int sum=abs(a[j]-a[j-1])*(j-i);
//			cout<<sum<<" k="<<k-sum<<", ";
			if(k<sum){
				j--;
				ans=max(ans,j-i+1);
				ok=0;
				break;		
			}
			k-=sum;
		}
		if(ok){
			ans=max(ans,n-i+1);
		}
//		cout<<endl;
	}
	cout<<ans;
	return 0;
}
