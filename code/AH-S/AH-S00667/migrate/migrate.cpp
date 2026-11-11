#include<bits/stdc++.h> 
using namespace std;
int f[1000005];
long long a[1000005],n,d,sum,l,T;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>l>>T;
	while(T--){
		sum=0;
		memset(a,0,sizeof a);
		memset(f,0,sizeof f);
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<n-1;i++){
			if(d<a[i+3]-a[i]&&d>=a[i+3]-a[i+2]&&d>=a[i+2]-a[i]&&d>=a[i+3]-a[i+1]&&d>=a[i+1]-a[i]){
				f[i+3]=4;
				f[i]=1;
				sum++;
			}
		}

		for(int i=2;i<=n;i++){
			if(f[i]==0&&(f[i-1]==4||f[i-1]==3)&&d<a[i]-a[i-2]&&d>=a[i]-a[i-1]){
				f[i]=3;
				sum++;
			}
		}
		for(int i=n-1;i>=1;i--){
			if(f[i]==0&&f[i+1]==1||f[i+1]==2&&d<a[i+2]-a[i]&&d>=a[i+1]-a[i]){
				f[i]=2;
				sum++;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
