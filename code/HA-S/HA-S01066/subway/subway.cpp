#include<bits/stdc++.h>
using namespace std;
int c;
long long n;
long long m;
long long d;
long long q;
long long k;//第i条线路的站数 
long long a;
long long l,r;
long long ans=0;
long long kt[550];//第i站站口到站台time 
long long t[550][550];//第 i站到第j条线路时间 
long long nn[550][550];//i,0为第i条线路的站数 ，i，j为第i线路的第j个站 
long long f[550][550];//i站到j站最短时间 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c;
	cin>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>kt[i];
	}
	for(long long i=1;i<=n;i++){
		cin>>k;
		nn[i][0]=k;
		for(long long j=1;j<=k;j++){
			cin>>a;
			cin>>t[a][i];
			nn[i][j]=a;	
		}
	}
//	for(long long i=1;i<=m;i++){
//		for(long long j=1;j<=m;j++){
//			f[i][j]=-1;
//		}
//	}
	for(long long i=1;i<=n;i++){
		long long e=nn[i][0];
		for(long long x=1;x<=e;x++){
			for(long long y=x;y<=e;y++){
				f[nn[i][x]][nn[i][y]]=t[nn[i][x]][i]+t[nn[i][y]][i];
			}	
		}
	}
	while(q!=0){
		cin>>l>>r;
		ans+=kt[l]+kt[r];
		ans+=f[l][r];
		
		cout<<ans<<endl;
		q--;
	}
	
}
