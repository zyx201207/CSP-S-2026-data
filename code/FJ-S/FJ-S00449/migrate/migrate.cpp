#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define mn 2000006
using namespace std;
long long c,n,t,k,x[mn],l,f[mn],j,amn[mn],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	for(int rp=1;rp<=t;rp++){
		cin>>n>>k;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++) f[i]=0,amn[i]=11111111;
		ans=0;
		for(int i=1;i<=n;i++){
			l=i;
			f[i]=1,amn[i]=0;
			for(j=i+1;j<=n;j++){
				while((x[j]-x[l])>k) l++;
				if(l==j) break;
				amn[j]=amn[l];
				if((l<j)&&(amn[l]==amn[j])) f[j]+=f[l];
				if((l+1<j)&&(amn[l+1]==amn[j])) f[j]+=f[l+1];
				if((l+2<j)&&(amn[l+2]==amn[j])) f[j]+=f[l+2];
				f[j]=min(f[j],3ll);
				if(f[j]==2) ans++;
				amn[j]++;
			}
			for(int o=i;o<=j;o++) f[o]=0,amn[o]=11111111;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
