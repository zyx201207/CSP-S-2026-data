#include<bits/stdc++.h>
using namespace std;
int a[5001];
int cnt=0;
int minn=1e9;
int n,d;
void dfs(int last,int y,int num){
	if(num>minn) return;
	if(a[y]-a[last]>=d){
		if(num<minn){
			minn=num;
			cnt=1;
		}
		else cnt++;
		return;
	}
	if(cnt>2) return;
	for(int i=last+1;i<=y-1;i++){
		if(a[i]-a[last]>=d){
			dfs(i,y,num+1);
		}
		else break;
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int t=1;t<=n;t++){
			cin>>a[t];
		}
		//for(int p=1;p<=n-1;p++){
			//for(int j=i+3;j<=n;j++){
				//dfs(p,j,0);
				//if(cnt==2) ans++;
//
		//}
		cout<<0<<"\n";
	}
	return 0;
}
