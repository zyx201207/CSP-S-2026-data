#include<bits/stdc++.h>
using namespace std;
long long z[200005];
int n,m;
long long Ans=-1;
int db[32]={0,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728};
void dfs(int cs,long long x){
	if(cs==m+1){
		Ans=max(Ans,x);
		return;
	}
	for(int i=cs;i<=n;i++){
		if(cs==1) x=z[i];
		else x=long(x&z[i]);
		dfs(cs+1,x);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	
	cin>>n>>m;
	
	for(int i=1;i<=25;i++){
		if(n==db[i]){
			for(int j=1;j<=n;j++) cin>>z[j];
			if(m>n/2){
				cout<<0;
				return 0;
			}
			else{
				for(int j=1;j<=25;j++){
					if(db[j]>=m){
						cout<<z[n-db[j]+1];
						return 0;
					}
				}
			}
		}
	}
	
	if(m==1){
		long long Max=-1; 
		for(int i=1;i<=n;i++){
			cin>>z[i];
			Max=max(Max,z[i]);
		}
		cout<<Max;
		return 0;
	}
	
	if(m==n){
		long long ans=0;
		for(int i=1;i<=n;i++){
			cin>>z[i];
			if(i==1) ans=z[i];
			else ans=long(ans&z[i]);
		}
		cout<<ans;
		return 0;
	}
	
	bool ok=0;
	long long MAx=-1;
	for(int i=1;i<=n;i++){
		cin>>z[i];
		MAx=max(z[i],MAx);
		for(int i=1;i<=25;i++){
			ok=1;
			if(z[i]==db[i]-1){
				ok=0;
				break;
			}
		}
		
	}
	
	if(ok==0){
		sort(z+1,z+1+n);
		cout<<z[n-m+1];
		return 0;
	}
	
	
	dfs(1,0);
	


	
	
	return 0;
} 
