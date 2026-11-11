#include<bits/stdc++.h>
using namespace std;
long long ans,cnt,x=32,n,m,a[200005],yy;
long long e[200005][34];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		a[i]=1;
		cin>>yy;
		while(yy){
			e[i][++e[i][0]]=yy%2;
			yy/=2;
		}
	}
	while(--x){
		cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0)continue;
			if(e[i][0]>=x){
				cnt+=e[i][x];
			}			
		}//cout<<cnt<<" "<<x<<endl;
		if(cnt>=m){
			ans+=(1<<x);
			for(int i=1;i<=n;i++){
				
				if(a[i]==0)continue;
				if(e[i][0]<x)a[i]=0;
				else a[i]=e[i][x];//cout<<a[i]<<" ";
			}//cout<<endl;
		}
	}
	cout<<ans/2;
	return 0;
} 
