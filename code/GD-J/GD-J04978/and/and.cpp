#include<bits/stdc++.h>
using namespace std;
long long int f[100000086],ans=-1,cnt;
long long int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;

	for(long long int i=1;i<=n;i++){
		cin>>f[i];
	} 
	if(m==2){
		for(long long int i=1;i<=n;i++){
			for(long long int j=1;j<=n;j++){
				if(i!=j) ans=max(ans,f[i]&f[j]);
			}
		}
	}if(m==3){
		for(long long int a=1;a<=n;a++){
			for(long long int i=1;i<=n;i++){
				for(long long int j=1;j<=n;j++){
					if(i!=j and a!=j and a!=i) ans=max(ans,f[i]&f[j]&f[a]);
				}
			}
		}
	}
	if(m==4){
		for(long long int b=1;b<=n;b++){
			for(long long int a=1;a<=n;a++){
				for(long long int i=1;i<=n;i++){
				for(long long int j=1;j<=n;j++){
						if(i!=j and a!=j and a!=i and a!=b and b!=i and b!=j) ans=max(ans,f[i]&f[j]&f[a]&f[b]);
					}
				}
			}
		}
	}if(m==5){
		for(long long int c=1;c<=n;c++){
			for(long long int b=1;b<=n;b++){
				for(long long int a=1;a<=n;a++){
					for(long long int i=1;i<=n;i++){
						for(long long int j=1;j<=n;j++){
							if(i!=j and a!=j and a!=i and a!=b and b!=i and b!=j and c!=i and c!=j and c!=a and c!=b) ans=max(ans,f[i]&f[j]&f[a]&f[b]&f[c]);
						}
					}
				}
			}
		}	
	}
	cout<<ans;
	return 0;
} 
