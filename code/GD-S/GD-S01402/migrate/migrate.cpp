#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
int n;
ll a[N],d,f[N],cnt[N],buk[N];
int q[N];
void sol1(){
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++)f[j]=1e18,cnt[j]=0;
		f[i]=0;cnt[i]=1;
		for(int j=i+1;j<=n;j++){
			int p=j-1;
			while(p>=i&&a[j]-a[p]<=d){
				f[j]=min(f[j],f[p]+1);
				p--;
			}
			for(int k=p+1;k<j;k++){
				if(f[k]+1==f[j])cnt[j]+=cnt[k];
			}
			if(cnt[j]==2)ans++;
			
		}
	}
	cout<<ans<<"\n";
}
void sol2(){
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++)f[j]=1e18,cnt[j]=0;
		for(int j=1;j<=n;j++)buk[j]=q[j]=0;
		f[i]=0;cnt[i]=1;
		int h=1,t=1;
		q[1]=i;buk[0]=1;
		for(int j=i+1;j<=n;j++){
			while(a[j]-a[q[h]]>d&&h<=t){
				buk[f[q[h]]]-=cnt[q[h]];
				h++;
			}
			while(f[j]<f[q[t]]&&h<=t){
				buk[f[q[t]]]-=cnt[q[t]];
				t--;
			}

			f[j]=f[q[h]]+1;
			cnt[j]=buk[f[q[h]]];
			q[++t]=j;
			buk[f[j]]+=cnt[j];
			if(cnt[j]==2)ans++;
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(c<=6)sol1();
		else if(c<=10)sol2(); 
	}
	return 0;
}
