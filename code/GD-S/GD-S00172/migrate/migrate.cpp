#include<bits/stdc++.h>
using namespace std;
struct itn{
	long long zb;//坐标
	long long zdl;//最短路
	long long fa;//方案 
}f[2000005];
long long c,t,n,d,ans;
void zdl(int s,int m){
	for(int i=s;i<=n;i++){
		for(int j=i-1;j>=m;j--){
			if(f[i].zb-f[j].zb<=d){
				if(f[i].zdl==f[j].zdl+1){
					f[i].fa+=f[j].fa;
				}else if(f[i].zdl>f[j].zdl+1){
					f[i].zdl=f[j].zdl+1;
					f[i].fa=1;
				}
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>f[i].zb; 
			f[i].zdl=1145140;
			f[i].fa=0;
		}
		
		for(int i=1;i<=n-1;i++){
			f[i].zdl=1;
			f[i].fa=1;
			int k;
			for(int j=i+1;j<=n;j++){
				if(f[j].zb-f[i].zb<=d){
					f[j].fa=1;
					f[j].zdl=1;
					k=j;
				}else{
					break;
				}
			}
			zdl(k+1,i);
			for(int j=1;j<=n;j++){
				if(f[j].fa==2){
					ans++;
				}
				f[j].fa=0;
				f[j].zdl=1145140;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
