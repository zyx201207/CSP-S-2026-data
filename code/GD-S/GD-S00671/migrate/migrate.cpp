#include<bits/stdc++.h>
using namespace std;
const long long I=2e6+1;
long long x[I];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		int l;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(x[1]<0){
				l=abs(x[1]);
				x[i]+=l;
			}
		}
		if(d*2>n){
			cout<<0<<endl;
		}else{
			int ans=0;
			for(int i=1;i<=n;i++){
				int a[5000];
				for(int j=1;j<=d;j++){
					for(int z=d;z>=1;z--){
						int k=0;
						k=x[i]+j;
						while(k<=x[n]){
							a[k]++; 
							k+=z;
						}
					}
				}
				for(int j=1;j<=n;j++){
					if(a[j]==2 && (i+d)!=j){
						ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
