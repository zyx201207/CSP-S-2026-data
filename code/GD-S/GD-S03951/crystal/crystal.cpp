#include<bits/stdc++.h>
using namespace std;
const int N=500100;
long long a[N],m,n,t,cnt,d[N][N],ans,cntt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
		if(m>=1e8+1){
		for(int i=2;i<=n;i++){
			if(m<((i-1)*i)/2){
				cout<<i-1;
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	d[1][1]=0;
	for(int i=2;i<=n;i++){
		for(int j=i;j<=n;j++){
			d[i][j]=a[j]-a[i];
		}
	}
	for(int i=1;i<=n;i++){
		ans=0;
		cnt=0;
		for(int j=1;j<=i;j++){
			if((ans+d[i][j])<=m){
				ans+=d[i][j];
				cnt++;
			}else{
				cntt=max(cnt,cntt);
				continue;
			}
		}
	}
	cout<<cntt;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
