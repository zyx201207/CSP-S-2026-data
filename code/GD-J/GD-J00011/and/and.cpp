#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
bool vis[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	//cout<<(n&m);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	int cnt=0;
	int ans=0;
	for(int t=1<<30;t;t>>=1){
		cnt=0;
		for(int i=1;i<=n;i++){
			if(vis[i])continue;
			if(a[i]&t){
				cnt++;
			}
		}
		if(cnt>=m){
			ans+=t;
			//cout<<cnt<<" "<<t<<endl;
			for(int i=1;i<=n;i++){
				if(vis[i])continue;
				if(!(a[i]&t)){
					vis[i]=1;
				}
			}	
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
