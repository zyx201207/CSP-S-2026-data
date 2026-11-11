#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,t,n,d,x[N],f[1005][1005],cnt;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(x,0,sizeof(x));
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i]; 
		if(n<=1000){
			for(int i=1;i<=n;i++)f[i][i]=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(j>2)
						for(int k=1;k<=j;k++)
							if(abs(x[k]-x[i])<=d&&abs(x[j]-x[k])<=d)f[i][j]+=f[k][i]+1;
				}
			}
			int cnt=0;
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					if(f[i][j]==2)cnt++;
			cout<<cnt<<endl;
		}
		else{
			cnt=0;
			for(int i=1;i<=n-3;i++)
				if(abs(x[i]-x[i+3])<=2*d&&abs(x[i]-x[i+3])>d)cnt++;
			cout<<cnt<<endl;
		}
	}
	return 0;
}

