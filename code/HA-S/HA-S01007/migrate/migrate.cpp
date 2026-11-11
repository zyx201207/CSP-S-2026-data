#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long x[N];
int num(int u,int v,int d){
	if(u>=v){
		return 1;
	}
	int sum=x[u],ans=0;
	for(int i=u+1;i<=v;i++){
		if(sum>d){
			break;
		}
		ans+=num(i,v,d);
		sum+=x[u];
	}
	return ans;
}
bool sj(int u,int v,int d){
	if(num(u,v,d)==2){
		return 1;
	}
	return 0;
}
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
		int sum =0;
		for(int u=1;u<n;u++){
			for(int v=u+1;v<=n;v++){
				if(sj(u,v,d)){
					sum++;
				}
			}
		}
		cout<<sum<<"\n";
	}
	
	
	return 0;
} 
