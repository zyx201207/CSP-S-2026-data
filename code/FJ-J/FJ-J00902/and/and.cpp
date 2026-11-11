#include<bits/stdc++.h>
using namespace std;

const int N=2e3+5;
int n,m,a[2005],ans;
bool dis[2005];
int d[2005];

void f(int cnt,int sum){
	if(cnt==m){
		ans=max(ans,sum);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!dis[i]){
			dis[i]=1;
			d[cnt+1]=a[i];
			f(cnt+1,(sum&a[i]));
			dis[i]=0;
			d[cnt+1]=0;
		}else continue;
	} 
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++) ans=max(ans,a[i]);
		cout<<ans;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,(a[i] & a[j]));
			}
		}
		cout<<ans;
	}else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=(ans & a[i]);
		}
		cout<<ans;
	}else{
		if(n<=24){
			for(int i=1;i<=n;i++){
				dis[i]=1;
				d[1]=a[i];
				f(1,a[i]);
				d[1]=0;
				dis[i]=0;
			}
			cout<<ans;
		}
	}
	return 0;
}
