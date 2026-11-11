#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],s[35],k[N],b[N][35];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	memset(s,0,sizeof s);
	memset(k,0,sizeof k);
	int n,m,p=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int o=0;
	for(int i=1;i<=n;i++) o=max(o,a[i]);
	while(o){
		o/=2;
		p++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=p;j++){
			int u=((a[i]&1)^1);
			s[j]+=u;
			b[i][j]=u;
			a[i]/=2;
		}
	}
	int ans=0;
	m=n-m;
	for(int i=p;i>0;i--){
		if(m>=s[i] && s[i]>=0){
			m-=s[i];
			for(int j=1;j<=n;j++){
				if(b[j][i] && !k[j]){
					k[j]=1;
					for(int l=1;l<i;l++) s[l]-=b[j][l];
				}
			}
			ans+=(1<<(i-1));
		}
	}
	cout<<ans;
	return 0;
}
