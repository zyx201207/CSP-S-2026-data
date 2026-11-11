#include<bits/stdc++.h>
using namespace std;
long long n,m,d[500005],maxx = -9;
long long k[500005];  
long long ans[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>d[i];     
	}
	sort(d+1,d+1+n);
	for(long long q=1;q<=n;q++){		
		memset(k,0,sizeof(k));
		for(int j=1;j<=n;j++){
			k[j] = abs(d[q]-d[j]); 			
		}
		sort(k+1,k+1+n);
		for(long long j=1;j<=n;j++){
			ans[j] = ans[j-1] + k[j];
			if(ans[j] <= m){
				maxx = max(maxx,j);
			}
		}
	}	
	cout<<maxx;
	return 0;
} 
