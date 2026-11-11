#include<iostream>
using namespace std;
long long n,m,a[200001],b[32];
bool f[200001];
void v(long long x){
	if(x==-1){
		for(int i=1;i<=n;i++) if(!f[i]) for(int j=0;j<=31;j++) if((a[i]>>j)&1) b[j]++;
	}else for(int i=1;i<=n;i++) if(!((a[i]>>x)&1)) f[i]=1;
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	v(-1);
	for(long long i=31;i>=0;i--){
		if(b[i]<m) continue;
		v(i);
		for(int j=0;j<=31;j++) b[j]=0;
		v(-1);
	}
	long long ans=(1ll<<31)-1;
	for(int i=1;i<=n;i++) if(!f[i]) ans=ans&a[i];
	cout<<ans;
	return 0;
}
