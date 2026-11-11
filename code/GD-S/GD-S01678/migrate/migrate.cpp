#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+5;
long long n,m,c,a[N],b[N],f[5005][5005],ff[5005][5005],sum,js,t,k,ans,x,y,z,minn,flag;
void solve1(){
	cin>>n>>m;
	ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=ff[i][j]=0;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
//			cout<<i<<" "<<j<<":";
			if(i==j)
				f[i][j]=1,ff[i][j]=0;
			else{
				minn=1e18;
				for(int k=j-1;k>=i;k--){
					if(((a[j]-a[k])>m))
						break;
					if(ff[i][k]<minn)
//						cout<<i<<" "<<k<<" "<<ff[i][k]<<" "<<f[i][k]<<"\n";
						f[i][j]=0,minn=ff[i][k],ff[i][j]=ff[i][k]+1;
					if(ff[i][k]==minn)
//						cout<<f[i][j]<<" ";
						f[i][j]+=f[i][k];
//						cout<<f[i][j]<<" "<<minn<<"\n";
				}
			}
				
//			cout<<"\n";
			if(f[i][j]==2)
				ans++;
//			cout<<ff[i][j]<<" ";
		}
//		cout<<"\n";
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++)
//			cout<<ff[i][j]<<" ";
//		cout<<"\n";
//	}
		
	cout<<ans<<"\n";
	return;
}
//void solve2(){
//	cin>>n>>m;
//	flag=1;
//	for(int i=1;i<=n;i++){
//		cin>>a[i];
//		if(i>=2){
//			if((a[i]-a[i-1])>m)
//				flag=0;
//			sum+=a[i]-a[i-1];
//			if(sum>=m)
//				js++,sum=0;
//		}
//	}
//	if(!flag){
//		cout<<0;
//		return;
//	}
//}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T=1;
	cin>>c;
	cin>>T;
	while(T--){
		if(c<=10)
			solve1();
//		if(c<=12)
//			solve2();
	}
	return 0;
} /*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
