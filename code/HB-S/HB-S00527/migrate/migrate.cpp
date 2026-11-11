#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long n,d;
long long c,t;
long long a[N];
long long dis[5005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;int fl=1;
		for(int i=1;i<=n;i++){cin>>a[i];dis[0]=a[1];if(i!=1)dis[i]=a[i]-a[1];if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2])fl=0;}
	//	for(int i=1;i<=n;i++)cout<<dis[i]<<" ";
		if(n<=5000){int tot=0;
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					int len=dis[j]-dis[i];
					if(len>d&&len<2*d){
						//cout<<i<<" "<<j;
						int uu=0;
						for(int k=i+1;k<j;k++){
							if(dis[k]-dis[i]<d)uu++;
						}//cout<<uu;
						if(uu==1)tot++;
					}
				}
			}cout<<tot<<"\n";
			continue;
		}
		if(fl){
			if(a[2]-a[1]>d||a[3]-a[1]>d||a[2]==a[1]){cout<<0<<"\n";continue;}
			int u=d/(a[2]-a[1]);
			cout<<max(n-u-2,0ll)<<"\n";
			continue;
		}
		
	}
	return 0;
}/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
