#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
long long c,T,d,n;
long long a[N]; 
long long f[N][N];
int dmax(long long x,long long y){
	long long num=0;
	long long i=x,j=x+1;
	while(1){
		while(1){
			if(a[j]-a[i]<=d) j+=1;
			if(a[j]-a[i]>d) break;
		}
		num+=1;
		i=j;
		j+=1;
		if(j>=y) break;
	}
	return num;
}
int dfs(long long x,long long y,long long step){
	long long sum=0;
	if(step==0) {
		if(a[y]-a[x]<=d) sum+=1;
		return sum; 
	}
	sum=1;
	for(long long i=x;i<=y;i++){
		if(a[i]-a[x]<=d) {
			sum+=dfs(i,y,step-1);
		}
	}
//	cout<<sum-1<<endl;
	return sum-1;
}
bool ff(long long x,long long y){
	if(y-x<=2 or a[y]-a[x]<=d) return false;
	long long step=dmax(x,y);
	long long sum=dfs(x,y,step);
//	cout<<sum<<endl;
	if(sum==2) return true;
	else return false;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		long long ans=0;
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				if(ff(i,j)==true) ans+=1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
