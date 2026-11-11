#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
const long long N=1e5*5+10;
long long s[N];
long long vis[N];
string a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=n;i>=1;i--){
		int wc=n-i+1;
		for(int j=n;j>=wc;j--){
			if(vis[s[j]]==0){
				vis[s[j]]=1;
				a[i]+=s[j];
			}				
			if(vis[s[j]]==1){
				for(int k=n;k>wc;k--){
					if(s[k]!+s[j]){
						a[i]-=s[k];
					}else{
						break;
					}
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=n;j>=1;j--){
			for(int k=0;k<a[j];k++){
				if(a[k]==i){
					ans++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 
