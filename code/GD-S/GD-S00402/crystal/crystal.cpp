#include<bits/stdc++.h>
using namespace std;
const int N=5e5+9;
long long a[N];
long long cf[N],pc[N];
void solved(){
	int n,m; cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i]; 
	}
	sort(a+1,a+n+1);
	long long ans=0;
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			cf[j]=abs(a[i]-a[j]);
			pc[j]=pc[j-1]+cf[j];
		}
		for(long long l=1;l<=n;l++){
			for(long long r=l;r<=n;r++){
				if((pc[r]-pc[l-1])<=m){
					ans=max(ans,r-l+1);
				}
			}
		} 
	} 
	cout<<ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	//cout<<fixed<<setprecision(2);
	solved();
	return 0;
} 

