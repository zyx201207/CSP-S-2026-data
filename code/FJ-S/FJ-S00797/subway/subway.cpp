#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[505],l;
long long a[505][505];
void ff(){
	for(int i=1;i<=m-2;i++)
	{
		for(int j=i+1;j<=m-1;j++)
		{
			for(int j2=j+1;j2<=m;j2++){
				if(a[i][j]!=0 && a[j][j2]!=0){
					if(a[i][j2]==0) a[i][j2]=a[i][j]+a[j][j2];
				}else a[i][j2]=min(a[i][j2],a[i][j]+a[j][j2]);
				
			}
		}
	}return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>l;
		for(int j=1;j<=l;j++){
			long long cc,k;
			cin>>cc;
			cin>>k;
			if(a[cc][i]==0) a[cc][i]=k;
			else a[cc][i]=min(a[cc][i],k);
			a[i][cc]=a[cc][i];
		}
	}
	ff();
	while(q--){
		long long r1,r2;
		cin>>r1>>r2;
		cout<<a[r1][r2]+w[r1]+w[r2]+a[r1][r1]<<" ";
	}
	return 0;
}
