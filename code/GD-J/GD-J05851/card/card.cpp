#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],x,s[300005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	long long T=n;
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++) cin>>a[i];
	while(T--){
		memset(s,0,sizeof(s));
		for(int i=n-T;i<=n;i++){
			s[a[i]]++;
			if(s[a[i]]==2){
				x=i;
				while(a[x]!=a[i] or x==i){
					s[a[x]]--;
					x--;
				}
			}
		}
		for(int i=1;i<=m;i++)
			if(s[i]==1) ans[i]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
} 

