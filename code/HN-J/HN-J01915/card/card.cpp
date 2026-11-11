#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int st,ans[N];
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n>500){
		for(int i=1;i<=n;i++) if(a[i]!=a[i+1]) ans[a[i]]=i;
	}
	else{
		int k=n;
		while(k--){
			st++;
			int cnt=0;
			int k[N];
			for(int i=st;i<=n;i++){
				for(int j=1;j<=cnt;j++){
					if(k[j]==a[i]){
						cnt=j-1;
						break;
					}
				}
				k[++cnt]=a[i];
			}
			for(int i=1;i<=cnt;i++) ans[k[i]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
} 
