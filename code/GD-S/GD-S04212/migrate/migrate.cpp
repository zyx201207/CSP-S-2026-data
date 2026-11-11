#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int a[100005],x[5005][5005],y[5005][5005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate,out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>t;
	bool q=0;
	int p=0;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		for(int k=1;k<=n;k++){
			if(k>a[i]-a[k-1]) q=1;
			p=a[k]-a[k-1];
		}
		if(p==0){
			if(d<=p){
				cout<<0<<'/n';
				continue;
			}else if(2*d<p){
				cout<<0<<'/n';
				continue;
			}else{
				cout<<p/d<<'/n';
			}
		}
		int d=0;
		for(int k=1;k<=n;k++){
			for(int z=k+1;z<=n;z++){
				if(a[z]-a[k]<=d) continue;
				cout<<a[z];
			}
			if(d==1) break;
		}
	}
	
	return 0;
}
