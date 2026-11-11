#include<bits/stdc++.h>
using namespace std;
int ans=0,n,m,a[100005],del[100005];
int step(int x,int y,int cnt){
	if(x==y)return cnt;
	if(x>y){
		int s=1;
		while(a[x]-a[x-s]<=m){
			s++;
		}
		step(x-s,y,cnt+1);
	}else{
		int s=1;
		while(a[x+s]-a[x]<=m){
			s++;
		}
		step(x+s,y,cnt+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<n;i++){
			del[i]=a[i+1]-a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int far1=step(i,j,0),far2=step(j,i,0);
				if(far1==far2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}