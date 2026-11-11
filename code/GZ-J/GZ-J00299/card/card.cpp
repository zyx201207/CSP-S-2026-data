//GZ-J00299,×ñÒåËÄÖĞ£¬Ô¬¼Îòà 
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005],t[300005],mp[500005],b[500005],c[300005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[a[i]]++;
	}
	if(m==1){
		cout<<(n+1)/2;
	}else if(n<=500){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				int o=j;
				for(int k=j-1;k>=i;k--){
					if(a[k]==a[j]&&b[k]==0){
						o=k;
						break;
					}
				}
				for(int k=o+1;k<=j;k++){
					b[k]=1;
				}
			}
			for(int j=i;j<=n;j++){
				if(b[j]==0){
					t[a[j]]++;
				}else{
					b[j]=0;
				}
			}
		}
		for(int i=1;i<=m;i++){
			cout<<t[i]<<" ";
		}
	}else{
		int ans=0;
		for(int i=1;i<=m;i++){
			ans+=c[i];
			cout<<ans<<" ";
		}
	}
	return 0;
}

