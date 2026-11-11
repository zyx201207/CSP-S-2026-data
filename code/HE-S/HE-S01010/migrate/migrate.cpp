#include<bits/stdc++.h>
using namespace std;
int n,d,x[20000],fans,ans;
void dfs(int s,int e,int i){
	if(i>e){
		return;
	}
	if(i==e){
		fans++;
		return;
	}
	int now=x[i];
	while(i<n&&x[i]-now<=d){
		dfs(s,e,i++);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int a=0;a<n;++a){
			cin>>x[a];
		}
		for(int a=0;a<n;++a){
			for(int b=a;b<n;++b){
				dfs(a,b,a);
				if(fans==2){
					ans++;
				}
				fans=0;
			}
		}
		cout<<ans<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
