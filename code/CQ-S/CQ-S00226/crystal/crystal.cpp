#include<bits/stdc++.h>
#define int long long
#define N 500005
using namespace std;

int n,m,a[N];

int ans;

int A=1,B=1;

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) A=0;
		if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]) B=0;
	}
//	cout<<B<<endl;
	if(A){
		for(int i=2;i<=n;i++){
			m-=i-1;
			if(m<0) break;
			ans=i;
		}
		cout<<ans;
	}else if(B){
		for(int i=2;i<=n;i++){
			m-=(a[2]-a[1])*(i-1);
			if(m<0) break;
			ans=i;
		}
		cout<<ans;
	}else{
		sort(a,a+n);
		for(int j=1;j<=n;j++){
			int m1=m;
			for(int i=j+1;i<=n;i++){
				m1-=(a[i]-a[i-1])*(i-j);
				if(m1<0) break;
				ans=max(ans,i-j+1);
			}
		}
		cout<<ans;
	}
	return 0;
}
