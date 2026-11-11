#include<bits/stdc++.h>
using namespace std;
long long n,d,a[2000006],v[5005][5005],kind[5005][5005],pre[5005][5005];
long long ans;
void get(){
	ans=0;
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)v[i][j]=1e18;
	for(int i=1;i<=n;i++){
		v[i][i]=1;
		int l=i,r=i;
		kind[i][i]=1;
		pre[i][i]=1;
		for(int j=i+1;j<=n;j++){
			while(l<=j&&a[j]-a[l]>d)l++;
			if(l==j)break;
			v[i][j]=v[i][l]+1;
			r=max(l,r);
			while(r<j&&v[i][r]==v[i][r+1])r++;
			kind[i][j]=pre[i][r]-pre[i][l-1];
			pre[i][j]=pre[i][j-1]+kind[i][j];
			if(kind[i][j]==2)ans++;
//			cout<<l<<' '<<r<<' '<<i<<' '<<j<<' '<<kind[i][j]<<' '<<pre[i][r]<<' '<<pre[i][l-1]<<endl;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		if(c<=10)get();
		printf("%lld\n",ans);
	}
} 
