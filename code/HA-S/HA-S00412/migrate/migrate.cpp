#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,ans;
long long x[50005];
int f[5005][5005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int k=1;k<=t;k++){
		long long j,i;
		ans=0;
		memset(x,0,sizeof(x));
		memset(f,0,sizeof(f));
		cin>>n>>d;
		long long s=INT_MAX;
		for(j=1;j<=n;j++){
			cin>>x[j];
			if(x[j]-x[j-1]>d){
				s=min(s,j);
			}
		}
		s=min(s,n);
		f[1][1]=1,f[n][n]=1;
		for(i=1;i<s;i++){
			for(j=i+1;j<=s;j++){
				if(x[j]-x[i]<=d){
					f[i][j]=1;
				}
				else{
					long long a,b;
					a=x[j]-x[i];
					b=a%d;
					if(b==0) f[i][j]=1;
					else{
						//cout<<a<<" "<<d<<endl;
						f[i][j]=a/d+1;
					}
					//cout<<a<<" "<<b<<" "<<a/d<<endl;
					//cout<<f[i][j]<<" ";
				}
			}
		}
		for(i=1;i<s;i++){
			for(j=i+1;j<=s;j++){
				//cout<<f[i][j]<<" "<<i<<" "<<j<<endl;
				if(f[i][j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
