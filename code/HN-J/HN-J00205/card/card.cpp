#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],p[500005],d[500005],ans[500005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	long long cs=n;
	int sf=1;
	while(cs--){
		for(int i = n-cs;i<=n;i++){
			p[i]=a[i];
			d[a[i]]++;
			if(d[a[i]]>=2){
				for(int j = 1;j<=n;j++){
					d[j]=0;
					if(p[j]==a[i]) n=0;
					if(n==0){
						p[j]=0;
					}
				}
				n=1;
				p[i]=a[i];
				d[a[i]]++;
			}	
		}
		for(int i = 0;i<=m;i++){
			if(d[i]!=0) ans[i]++;
		}
		for(int j = 0;j<=n;j++){
			p[j]=0;d[j]=0;
		}
		
	}
	for(int i = 1;i <= m;i++) cout<<ans[i]<<' ';
	
	return 0;
} 
