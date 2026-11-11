#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int c,t;
	cin>>c>>t;
	while(t--){
		int ans=0;
		int n,b;
		cin>>n>>b;
		long long s[n+10]={};//岛坐标 
		for(int i=1;i<=n;i++){
			cin>>s[i];
		} 
		for(int i=1;i<=n;i++){//遍历起点 
			long long x[n+10]={};//多少岛屿可以到达此岛 
			x[i]=1;
			for(int j=i;j<=n;j++){//j为下一个起点之后
				if(x[j]==2){
					ans++;
					cout<<i<<"   "<<j<<endl;
				} 
				if(x[j]!=0){
					for(int k=j+1;k<=n;k++){//j飞到 k 
						if(s[k]<=s[j]+b){
							x[k]+=x[j];
						}else{
							break;
						}
					}
				}
			} 
		}
		cout<<ans-1<<endl;
	} 
	return 0;
}
//终 
