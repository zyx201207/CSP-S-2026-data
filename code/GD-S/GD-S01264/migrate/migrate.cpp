#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int t,a[N],cnt=1,dis,n,d,c;
void check(int s,int t,int x,int step){
	if(x==t){
		if(dis>step)cnt=1,dis=step;
		else if(dis==step)cnt++;
		return ;
	}
	for(int i=x+1;i<=t;i++){
		if(a[i]-a[x]<=d)check(s,t,i,step+1);
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans=0;cin>>n>>d;for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				cnt=1,dis=INT_MAX;
				check(i,j,i,0);
				if(cnt==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
