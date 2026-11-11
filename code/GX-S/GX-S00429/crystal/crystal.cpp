#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],b[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ans;
	bool f=0;
	cin>>n>>m;
	b[1]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=(a[i]-a[i-1])*(i-1)+b[i-1];
		if(b[i]>m&&f==0){
			f=1;
			ans=i-1;
		}
	}
	cout<<ans;
	return 0;
}//1 1 4 4 4 4 5
