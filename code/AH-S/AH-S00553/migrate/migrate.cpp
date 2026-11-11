#include<bits/stdc++.h>
using namespace std;
long long c,t,n,x[2000010],d,f,change;
void dfs(int s,int e,long long step){
	if(x[e]-x[s]<=d&&step==0){
		f=-1;
		return;
	}
	if(change>=3){
		f=-1;
		return;
	}
	if(x[e]-x[s]<=d&&step!=0){
		change++;
		return;
	}
	for(int i=s+1;i<=e;i++){
		if(x[i]-x[s]<=d){
			dfs(i,e,step+1);
		}
		else break;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int cnt=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				f=0;
				change=0;
				dfs(i,j,0);
				if(f!=-1&&change==2)cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
