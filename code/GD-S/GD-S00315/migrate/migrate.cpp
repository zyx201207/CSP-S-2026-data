#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int n,d,a[N],b[N];
bool check(int x,int y){
	int m=0,i=x,j=1;
	while((j+i)<=y){
		while((b[i+j]-b[i])>=d){
			j++;
		}
		if(j>1) m++,i+=j;
	}
	if(m==1) return 1;
	return 0;
}
void solve(){
	int ans=0,k;
	cin>>n>>d;
	bool flag1=1;
	b[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]+b[i-1];
		if(i>1){
			if(i==2) k=a[i]-a[i-1];
			else if((a[i]-a[i-1])!=k) flag1=false;
		}
	}
	if(flag1){
		cout<<n%d+1<<'\n';
		return ;
	}
	for(int i=1;i<=(n-3);i++){
		for(int j=i+3;j<=n;j++){
			if(check(i,j)){
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int C,T;
	cin>>C>>T;
	while(T--){
		solve();
	}
	return 0;
}
