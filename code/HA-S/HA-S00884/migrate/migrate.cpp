#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[200010],e=0;
void dfs(int x,int y){
	if(y%2!=0&&x%2!=0){
		e=0;
	}else if(y%2==0&&x%2==0){
		e=x/4;
	}
	if(x&2!=0&&y%2==0){
		e=x/4+1;
	}
	cout<<e<<"\n";
}
void sol(){
	cin>>n>>d;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==1||n==2){
		cout<<0<<endl;
		return;
	}
	if(n==3){
		if(d==1){
			cout<<0<<endl;
			return;
		}else if(d>1){
			if(a[0]-a[1]>d||a[1]-a[0]>d||a[1]-a[2]>d||a[2]-a[1]>d||a[0]-a[2]>d||a[2]-a[0]>d){
				cout<<0<<endl;
				return;
			}else{
				cout<<1<<endl;
				return;
			}
		}
	}
	dfs(n,d);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	while(t--){
		sol();
	}
	return 0;
}
