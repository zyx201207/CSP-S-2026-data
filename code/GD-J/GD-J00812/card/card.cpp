#include<bits/stdc++.h>
using namespace std;
long long n,m;
stack<long long> s;
long long ans[10000];
long long a[10000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long pan=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			pan=1; 
		}
	}
	if(pan==1){
		if(n>5000){
			for(int i=1;i<=n;i++){
				long long vis[10000]={0};
				for(int j=i;j<=n;j++){
						vis[a[j]]=1; 
				}
				for(int i=1;i<=m;i++){
					if(vis[i]==1){
						ans[i]++;
					}
				}
			}
			for(int i=1;i<=m;i++){
				cout<<ans[i];
				if(i!=m){
					cout<<" ";
				}
			}
		}else{
			for(int i=1;i<=n;i++){
				while(!s.empty()){
					s.pop(); 
				}
				long long vis[10000]={0};
				for(int j=i;j<=n;j++){
					if(vis[a[j]]!=0){
						while(s.top()!=a[j]){
							vis[s.top()]=0;
							s.pop();
						} 
					}else{
						vis[a[j]]=1;
						s.push(a[j]); 
					}
				}
				for(int i=1;i<=m;i++){
					if(vis[i]==1){
						ans[i]++;
					}
				}
			}
			for(int i=1;i<=m;i++){
				cout<<ans[i];
				if(i!=m){
					cout<<" ";
				}
			}
		}	
	}else{
		for(int i=1;i<=n;i++){
			long long vis[10000]={0};
			for(int j=i;j<=n;j++){
					vis[a[j]]=1; 
			}
			for(int i=1;i<=m;i++){
				if(vis[i]==1){
					ans[i]++;
				}
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i];
			if(i!=m){
				cout<<" ";
			}
		}
	
		
	}
	
}
