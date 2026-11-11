#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,t,ans,len,a[200005];char c[200005];
signed main(){
	freopen("string.in","r",stdin),freopen("string.out","w",stdout),cin>>n,t=n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i],len+=a[i];
	for(int i=1;i<=n;i++){
		k+=a[i];
		if(k<=len/2){
			while(t){
				if(a[t]>=a[i]){
					if(c[i]!=c[t])ans+=a[i];
					a[t]-=a[i],a[i]=0;
					break;
				}else{
					if(c[i]!=c[t])ans+=a[t];
					a[i]-=a[t--],a[t+1]=0;
				}
			}
		}else{
			a[i]+=len/2-k;
			while(t){
				if(a[t]>=a[i]){
					if(c[i]!=c[t])ans+=a[i];
					a[t]-=a[i],a[i]=0;
					break;
				}else{
					if(c[i]!=c[t])ans+=a[t];
					a[t]=0,a[i]-=a[t--];
				}
			}
			break;
		}
	}
	cout<<ans;
	return 0;
} 
