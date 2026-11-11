#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005][50],x1[50],maxx,max2;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i][0];
		maxx=max(maxx,a[i][0]);
		int j=1;
		while(a[i][0]!=0){
			a[i][j]=a[i][0]%2;
			a[i][0]/=2;
			j++;
		}
	}
	if(m==1) cout<<maxx;
	if(m==n){
		for(int j=1;j<=45;j++){
			x1[j]=a[1][j];
		}
		for(int i=2;i<=n;i++){
			for(int j=1;j<=45;j++){
				if(x1[j]==1&&a[i][j]==1)x1[j]=1;
				else x1[j]=0;
			}
		}
		long long cnt=0;
		for(int i=45;i>=1;i--){
			cnt*=2;
			cnt+=x1[i];
		}
		cout<<cnt;
	}
	if(m==2){
		for(int i=1;i<=n-1;i++){
			for(int j=1;j<=45;j++){
				x1[j]=a[i][j];
			}
			for(int k=i+1;k<=n;k++){
				for(int j=1;j<=45;j++){
					if(x1[j]==1&&a[k][j]==1)x1[j]=1;
					else x1[j]=0;
				}
			}
			long long cnt=0;
			for(int i=45;i>=1;i--){
				cnt*=2;
				cnt+=x1[i];
			}
			max2=max(max2,cnt);
		}
		cout<<max2;
	}
	return 0;
}
