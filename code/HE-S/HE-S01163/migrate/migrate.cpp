#include<bits/stdc++.h>
using namespace std;
long long a[500010]={};
long long b[500010]={};
long long sum[500010]={};
int ans=0;
int n;
long long d;
void dfs(int x,int y,int now,int cnt,int num){
	if(now==y){
		if(cnt==num){
			ans++;
		}
		return ;
	}
	
	for(int i=1;now+i<=y;i++){
		if(sum[now+i]-sum[now]<=d){
			dfs(x,y,now+i,cnt+1,num);
		}else{
			break;
		}
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int nas=0;
	while(t--){
		nas=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			b[i]=a[i]-a[i-1];
			b[1]=0;
			sum[i]=b[i]+sum[i-1];
		}
		if(n<4){
			cout<<0<<endl;
			continue;
		}
		if(n<=9){
			for(int i=1;i<=n;i++){
				for(int j=i+3;j<=n;j++){
					//zhaozuiduan
					int num=0,lst=i;
					for(int k=i;k<=j;k++){
						if(sum[k]-sum[lst]>d){
							num++;
							lst=k-1;
							if(sum[k]-sum[lst]>d){
								num=-1;
								break;
							}
						} 
					}
					if(num==-1){
						continue;
					}
					num++;
//					cout<<1;
					ans=0;
					dfs(i,j,i,0,num);
					if(ans==2){
//						cout<<i<<' '<<j<<endl; 
						nas++;
					}
				}
			}
		}
		cout<<nas<<endl;
	}
	return 0;
}
