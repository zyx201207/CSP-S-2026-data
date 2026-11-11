#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000001],ans;
int f(int start,int end){
	int cnt=0;
	if(x[end]-x[start-1]<=d) return 0;
	for(int j=start;j<=end;j++){
		if(x[j]-x[start-1]>d) return cnt;
		if(x[end]-x[j]<=d){
			cnt++;	
		}
	}	
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		ans=0;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}	
		for(int u=1;u<n;u++){
			for(int v=u+3;v<=n;v++){
				if(f(u+1,v)==2) ans++;				
			}
		}	
		cout<<ans<<endl;
	}
	return 0;
}
