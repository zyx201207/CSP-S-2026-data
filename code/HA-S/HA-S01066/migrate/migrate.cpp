#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d,v=0;
long long a[20006];
long long f[20006][20006];
long long b[20006][20006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t!=0){
		cin>>n>>d;
		v=0;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				b[i][j]==1;
			}
		}
		for(long long i=1;i<=n;i++){
			f[i][i]=1;
			for(long long j=i+1;j<=n;j++){
				for(long long x=j;j-x<=d and x>=i;x--){
					if(f[i][j]==f[i][x]){
						b[i][j]+=b[i][x];
					}else f[i][j]=min(f[i][j],f[i][x]+1);
				}	
			}	
		}
		for(long long i=1;i<=n;i++){
			for(long long j=i+3;j<=n;j++){
				if(a[j]-a[j-1]>d) break;
				if(b[i][j]==2) v+=1;
			}
		}
		cout<<v<<endl;
		t--;
	}
	return 0; 
}
