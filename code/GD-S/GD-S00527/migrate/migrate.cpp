#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005],f[2000005],g[2000005],ans,s[2000005],lst[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	if(c==0){
		while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;++i)cin>>a[i];
		long long p=a[2]-a[1];
		p=d/p;
		if(p==0||p==1){cout<<"0\n";continue;}
		for(int i=2;i<=n;++i)ans+=(n-p)/(p-1);
		cout<<ans<<'\n';
	}
	}
	else{
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;++i)cin>>a[i];
		for(int i=1;i<=n;++i){
			f[i]=0;s[i]=g[i]=1;lst[0]=i;
			int pos=i;
			for(int j=i+1;j<=n;++j){
				f[j]=n+1;g[j]=0;
				while(a[j]-a[pos]>d)++pos;
				f[j]=f[pos]+1;
				g[j]=s[lst[f[pos]]]-s[pos-1];
				if(g[j]==2)ans++;
				s[j]=s[j-1]+g[j];
				lst[f[j]]=j;
			}
			for(int i=0;i<=n+1;++i)lst[i]=g[i]=f[i]=s[i]=0;
		}
		cout<<ans<<'\n';
	}
	}
	return 0;
}

