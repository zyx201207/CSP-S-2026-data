#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005],ts;
long long mph(int x,int y){
	int k=x,s=0;
	for(int i=x+1;i<=y;i++){
		if(((a[i]-a[k])>d)and(i==k+1))return 0;
		if((a[i]-a[k])>d){
			k=i-1;
			s++;
		}
	}
	if(k!=y)s++;
	return s;
}
void bg(long long da,int x,int y,long long step){
	if(step>da)return;
	if(step==da and x!=y)return;
	if(step==da and x==y)ts++;
	for(int i=x+1;i<=y;i++){
		if((a[i]-a[x])>d)break;
		bg(da,i,y,step+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		long long sss=0;
		if(n==1 or n==2 or n==3){
			cout<<0;
			continue;
		}
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n-3;i++){
			for(int j=i+3;j<=n;j++){
				long long miny=mph(i,j);
				ts=0;
				if(miny==0)break;
				bg(miny,i,j,0);
				if(ts==2)sss++;
			}
		}
		cout<<sss<<endl;
	}
	return 0;
}
