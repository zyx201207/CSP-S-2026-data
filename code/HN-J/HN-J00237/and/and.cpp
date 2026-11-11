#include<bits/stdc++.h>
using namespace std;
int pos[10000];
int las;

int n,m;

long long mx=0;
long long a[200000];
long long dfs(int k){
	if(k==m){ 
		long long ans=a[pos[0]];

		for(int i=1;i<k;i++){
			
		 	ans=ans&a[pos[k]];
		}
		mx=max(mx,ans);
		return 0;
	}
	for(int i=0;i<n;i++){
		pos[k]=i;
		dfs(k+1);
	}
	
}


int main(){
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	dfs(1);
	cout<<mx;
    return 0;
}

