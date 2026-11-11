#include<bits/stdc++.h>
using namespace std;
long long n,t,c,d,a[2000005],g,e,b,f;
void dfs(int x,int s){
	if(x==e){
		if(s<b){
			b=s;
			f=1;
		}else if(s==b){
			f++;
		}
		return;
	} 
	for(int i=x+1;i<=e;i++){
		if(a[i]-a[x]>d)break;
		dfs(i,s+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		g=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				b=n+1;
				e=j;
				f=0;
				dfs(i,0);
				if(f==2){
					g++;
				}
			}
		}
		cout<<g<<endl;
	}
	return 0;
}
