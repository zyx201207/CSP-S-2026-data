#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t,n,d,a[2000010],f[2000010],g[2000010],s[2000010],ans;
ll head,tail,b[2000010],pt;
int main(){
	freopen("migrate.in" ,"r",stdin );
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;++i)cin>>a[i];
		for(int i=1;i<n;++i){
			pt=1;
			head=1;
			tail=1;
			b[1]=i;
			f[i]=0;
			g[i]=1;
			s[1]=1;
			f[0]=1e17;
			for(int j=i+1;j<=n;++j){
				while(tail<=head&&a[b[tail]]<a[j]-d)++tail;
				pt=max(pt,tail);
				while(pt<head&&f[b[pt]]==f[b[pt+1]])++pt;
				if(tail<=head){
					f[j]=f[b[tail]]+1;
					ll k=tail,sum=s[pt]-s[tail-1];
					g[j]=sum;
					b[++head]=j;
					s[head]=s[head-1]+g[j];
					if(sum==2)ans++;
				}else break;
//				cout<<i<<" "<<j<<" "<<g[j]<<" "<<f[j]<<'\n';
//				for(int kk=tail;kk<=head;++kk)cout<<b[kk]<<":"<<f[b[kk]]<<" ";cout<<'\n';
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
