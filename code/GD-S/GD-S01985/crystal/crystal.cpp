#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;

int n,m,ans;
int a[N],s[N],cf[N];
int f[N];

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		cf[i]=a[i]-a[i-1];
		//s[i]=s[i-1]+cf[i];
		//cout<<cf[i]<<endl;
		//cout<<a[i]<<endl; 
	}
	//cout<<endl;
	ans=m;
	//memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++){
		//cout<<ans<<endl;
		ans-=cf[i]*(i-1);
		if(ans<0){
			cout<<i;
			return 0;
		}
	}
	//cout<<a[n]-a[1]<<endl;
	cout<<n;
	return 0;
} 
