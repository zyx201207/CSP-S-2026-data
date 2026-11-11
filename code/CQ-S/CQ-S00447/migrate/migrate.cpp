#include<bits/stdc++.h>
using namespace std;
bool l[5005][5005],r[5005][5005];
long long t,n,a[100005],m,qzhl[5005][5005],qzhr[5005][5005],qzhl1[5005][5005],qzhr1[5005][5005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t>>t;
	while(t--){
		memset(l,0,sizeof(l)),memset(r,0,sizeof(r));
		long long n;cin>>n>>m;
		for(long long i=1;i<=n;i++)cin>>a[i];
		for(long long i=1;i<=n;i++){
			long long x=i; 
			for(long long j=i+1;j<=n&&a[j]-a[j-1]<=m;j++)if(a[j]-a[x]>m&&j!=x+1)x=j-1,l[i][j-1]=1;
			l[i][n]=1;
			x=i; 
			for(long long j=i-1;j>=1&&a[j+1]-a[j]<=m;j--)if(a[x]-a[j]>m&&j!=x-1)x=j+1,r[i][j+1]=1;
			r[i][1]=1;
		}
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++)
				qzhl[i][j]=qzhl[i][j-1]+j*l[i][j],qzhl1[i][j]=qzhl1[i][j-1]+l[i][j];
			for(long long j=n;j>=1;j--)
				qzhr[i][j]=qzhr[i][j+1]+j*r[i][j],qzhr1[i][j]=qzhr1[i][j+1]+r[i][j];
		}
		long long sum=0;
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n&&a[j]-a[j-1]<=m;j++){
				if(a[j]-a[i]<=m)continue;
				bool x24=0; 
				for(long long k=j-1;k>i;k--){
					if(r[j][k]==1){
						long long zn=0;
						for(long long l1=k;l1<j;l1++)
							if(l[i][l1]){zn=l1;break;}
						if(zn-k>1){x24=1;break;}
					}
				}
				bool fl=0;
				for(long long k=i+1;k<=j-1;k++){
					if(l[i][k]!=r[j][k])fl=1;
				}
				if(x24==0&&fl)sum++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
/*
0 3
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
6 3
0 1 2 3 4 7
8 3
0 1 2 4 8 10 11 13
2
*/
