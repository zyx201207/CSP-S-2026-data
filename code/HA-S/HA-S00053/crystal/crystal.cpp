#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;

long long n,m,ans=1,can;
long long f[N],w[N],a[N];

bool cmp(int x,int y){return x<y;}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int p=0;
	sort(a+1,a+n+1,cmp);
	f[1]=1;w[1]=0;
	int j=1;
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]){
			w[i]=w[i-1];
			f[i]=f[i-1]+1;
			ans=max(ans,f[i]);
			continue;
		}
		p=w[i-1]+f[i-1]*(a[i]-a[i-1]);
		while(j<=i&&p>m) p-=(a[i]-a[j]),j++;
		w[i]=p;
		f[i]=i-j+1;
		ans=max(ans,f[i]);
	}
//	for(int i=1;i<=n;i++) cout<<w[i]<<" ";
//	cout<<endl;
//	for(int i=1;i<=n;i++) cout<<f[i]<<" ";
//	cout<<endl;
	cout<<ans;
	
	return 0;
}
