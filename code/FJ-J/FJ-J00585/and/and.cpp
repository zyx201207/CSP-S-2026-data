#include<bits/stdc++.h>
using namespace std;
const int N=200010;
long long n,m;
long long x;
int a[N][33];
bool g[N]; 
long long ans=0;
void insert(long long s,int t){
	for(int k=30;k>=0;k--){
		if(s>=(1<<k)){
			s-=(1<<k);
			a[t][k]=1;
		}else{
			a[t][k]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		insert(x,i);
	}
	memset(g,true,sizeof(g));
	for(int i=30;i>=0;i--){
		long long sum=0;
		for(int j=1;j<=n;j++)
			if(a[j][i]==1&&g[j])sum++;
		if(sum<m)continue;
		ans+=(1<<i);
		for(int j=1;j<=n;j++)
			if(a[j][i]==0)g[j]=false;
	}
	cout<<ans<<endl;
	return 0;
}
