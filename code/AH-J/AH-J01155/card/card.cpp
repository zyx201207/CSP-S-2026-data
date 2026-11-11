#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5e5+10;
LL n,k,a[N],ans[N],t[N];
LL s[N],f[N];bool flag[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>k;
	t[0]=1;
	for(LL i=1;i<=n;i++){
		cin>>a[i];t[a[i]]++;
		if(s[a[i]]==0)s[a[i]]=i;
	}
	for(LL i=n;i>=1;i--){
		if(f[a[i]]==0) f[a[i]]=i;
	}
	for(LL i=1;i<=n;i++){
		t[a[i-1]]--;
		if(t[a[i-1]]==0){
			s[a[i-1]]=0;
			f[a[i-1]]=0;
		}else if(t[a[i-1]]==1){
			s[a[i-1]]=f[a[i-1]];
		}else{
			for(LL j=i;j<=n;j++){
				if(a[j]==a[i-1]){ s[a[i-1]]=j;break;}
			}
		}
		memset(flag,0,sizeof(flag));
		for(LL j=i;j<=n;j++){
			if(flag[j]==1) continue;
			if(t[a[j]]==1) ans[a[j]]++;
			else if(t[a[j]]>1){
				for(LL l=s[a[j]];l<=f[a[j]];l++){
					flag[l]=1;
				}
				ans[a[j]]++;
			}else continue;
		}
	}
	for(LL i=1;i<=k;i++) cout<<ans[i]<<" ";
	return 0;
}
