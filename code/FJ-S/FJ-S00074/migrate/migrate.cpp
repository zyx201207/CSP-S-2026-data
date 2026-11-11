//T3 migrate
#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000050];
int ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&c,&t);
	while(t--){
		scanf("%d %d",&n,&d);
		for(int i=1;i<=n;i++)scanf("%d",x+i);
		ans=0;
		int u=1;
		bool flag=0;
		for(int i=1;i<=n;i++){
			if(i==1&&x[i]-x[i-1]>d){
				u=1;
				flag=0;
				continue;
			}
			u++;
			if(u==4){
				if(x[i]-x[i-1]>d&&x[i]-x[i-2]<d)ans++,flag=1;	
			}
			if(u>4&&flag)ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
