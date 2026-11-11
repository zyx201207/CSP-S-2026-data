#include <bits/stdc++.h>

using namespace std;
int x[10001];

int main(){
	int c,t,n,d;
	cin>>c>>t;
	cin>>n>>d; 
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<=10001;i++){
		x[i]=10000;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int u=x[i];
			int v=x[j];
			if(u-v<=d){
				x[i]=min(x[i],u-i);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(x[i]==x[j]){
				ans++;
			}	
		}
	}
	cout<<ans;
	return 0;
} 
