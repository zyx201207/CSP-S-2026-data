//GZ-S00042 贵阳市观山湖区外国语实验中学 孙小涵 
#include<bits/stdc++.h>
using namespace std;
int x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		bool f=0;
		for(int u=1;u<n-1;u++){
			for(int v=u+2;v<=n;v++){
				if(x[v]-x[u]>d) {
					cout<<v-u<<"\n"; 
					f=1;
					break;
				}
			}
			if(f)break;
		}
		if(!f) cout<<0<<"\n";
	}
	return 0;
} 
