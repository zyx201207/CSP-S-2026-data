#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,x[2000001];
long long ans=1e9;
int f=0,e=0;
void dfs(int a,int m,int s){
	int b=1;
	if(a==s){
		if(m<ans){
			ans=m;
			f=1;
		}
		else if(m==ans){
			f++;
		}
		return;
	}
	while(x[a+b]-x[a]<=d && a+b<=s){
		dfs(a+b,m+1,s);
		b++;
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=1e9;
		e=f=0;
		cin>>n>>d;
		memset(x,1e18+1,sizeof(x));
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<n-1;i++){
			for(int j=i+2;j<=n;j++){
				dfs(i,0,j);
				if(f==2) e++;
			}
		}
		cout<<e<<endl;
	}
	return 0;
}

