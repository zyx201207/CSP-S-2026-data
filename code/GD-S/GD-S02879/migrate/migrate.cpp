#include<bits/stdc++.h>
using namespace std;
#define int long long

int rd(){
	int k=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c<='9'&&c>='0'){k*=10;k+=(c-'0');c=getchar();}
	return k*f;
}

const int N=2e6+7;

int n,d,a[N],pos[N],cnt[N],Is[N];

void solve(){
	n=rd();d=rd();
	for(int i=1;i<=n;i++)a[i]=rd();
	int ans=0,r=0;
	for(int i=1;i<=n;i++){
		int last=i,canget=i,idx=1;
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[last]>d){
				if(last==j-1){
					canget=last;
					break;
				}
				idx++;
				last=j-1;
			}
			canget=j;
			pos[j]=idx;
			cnt[pos[j]]++;
			r=max(pos[j],r);
		}
		for(int j=i+1;j<=canget;j++){
			if((cnt[pos[j]-1]==2&&Is[pos[j]]!=1)||(cnt[pos[j]]==1&&Is[pos[j]]==1)){
				ans++;
//				cout<<i<<" "<<j<<'\n';
				Is[pos[j]]=1;
			}
		}
		for(int i=0;i<=n;i++){
			cnt[i]=0;
			Is[i]=0;
		}
	}
	cout<<ans<<'\n';
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=rd(),t=rd();
	while(t--)solve();
	return 0;
}
