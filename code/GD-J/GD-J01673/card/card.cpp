#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
ll n,m,i,j,k;
ll a[N],cnt[N];
bool p[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	if(n<=500){
		for(i=1;i<=n;i++){
			memset(p,false,sizeof(p));
			for(j=i;j<=n;j++){
				if(!p[a[j]]) p[a[j]]=true;
				else{
					for(k=j-1;k;k--){
						if(a[j]==a[k]) break;
						else p[a[k]]=false;
					}
				}
			}
			for(j=1;j<=m;j++) cnt[j]+=p[j];
		}
		for(i=1;i<=m;i++) cout<<cnt[i]<<" ";
	}
	else{
		for(i=1;i<=m;i++) cout<<n<<" ";
	}
	return 0;
}
