#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=5e5+10,M=3e5+10;
ll n,m,a[N],f[M],ans[M];
//stack<ll> s;
ll s[N];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(f,0,sizeof(f));
		ll head=1,tail=1;
		for(int j=i;j<=n;j++){
			if(f[a[j]]==0){
				head++;
				s[head]=a[j];
				f[a[j]]=1;
			}
			else{
				while(s[head]!=a[j]){
					f[s[head]]=0;
					s[head]=0;
					head--;
				}
			}
		}
		while(head>=tail){
			ans[s[head]]++;
			s[head]=0;
			head--;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
