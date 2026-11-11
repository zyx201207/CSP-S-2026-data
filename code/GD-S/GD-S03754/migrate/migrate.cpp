#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,d,ans,f[2000007],a[2000007],len,b[2000007];
bool nb(int x,int y){
	f[x]=0;
	for(int i=x+1;i<=y;i++){
		f[i]=1e17;
		int s=0;
		for(int j=i-1;j>=x;j--){
			if(i!=y){
				if(a[i]-a[j]>d)break;
				else f[i]=min(f[i],f[j]+1);
			}else{
				if(a[i]-a[j]>d)break;
				else{
					if(f[j]+1<f[i]){
						f[i]=f[j]+1;
						s=1;
					}else s++;
				}
			}
		}
		if(i==y)return s==2;
	}
	return false;
}
void solve(){
	cin>>n>>d;
	len=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1&&a[i]-a[i-1]>d)b[++len]=i;
	}
	if(n>5000){
		cout<<0<<endl;
		return;
	}
	b[0]=1;
	b[len+1]=n+1;
	ans=0;
	for(int i=0;i<=len;i++){
		for(int j=b[i];j<=b[i+1]-4;j++){
			for(int k=b[i]+3;k<=b[i+1]-1;k++){
				if(nb(j,k))ans++;
			}
		}
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)solve();
	return 0;
}
