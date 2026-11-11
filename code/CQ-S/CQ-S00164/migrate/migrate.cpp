#include <bits/stdc++.h>
using namespace std;

int n;
int x[2000005];
int dist[2000005];
int t[200005];
int d;
long long ans;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t1;
	cin>>c>>t1;
	while(t1--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++){
			int k=i;
			memset(t,0x00,sizeof t);
			for(int j=i+1;j<=n;j++) dist[j]=1e9;
			t[0]=1;
			for(int j=i+1;j<=n;j++){
				while(x[k]<x[j]-d) t[dist[k]]--,k++;
				dist[j]=dist[k]+1;
				if(t[dist[k]]==2) ans++;
				t[dist[k]+1]++;
			}
		} 
		cout<<ans<<endl;
	}
	
	return 0;
}
