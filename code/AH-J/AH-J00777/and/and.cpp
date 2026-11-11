#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N],t[N][32],vis[N];
void C(long long id){
	long long x=a[id],tot=1;
	while(x!=0){
		if(x%2==1) t[id][tot]=1;
		else t[id][tot]=0;
		x/=2;
		tot++;
	}
	return ;
}
long long p(long long x){
	long long sum=1;
	for(int i=1;i<=x-1;i++) sum*=2;
	return sum;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	long long n,m,sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],C(i),vis[i]=1;
	for(int i=30;i>=1;i--){
		long long cnt=0;
		for(int j=1;j<=n;j++){
			if(t[j][i]==1&&vis[j]==1) cnt++;
		}
		if(cnt>=m){
			sum+=p(i);
			for(int j=1;j<=n;j++){
				if(t[j][i]==0&&vis[j]==1) vis[j]=0;
			}
		}
	}
	cout<<sum<<"\n";
	return 0;
}
