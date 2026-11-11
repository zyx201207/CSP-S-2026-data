#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int c,t,n,d,x[N],sum,ans,f,l;
void dfs(int w,int ed,int li){
//	cout<<w<<" "<<sum<<endl;
	if(li>l&&!f) return;
	if(w==ed){
		sum++;
		if(f){
			f=0;
			l=li;
		}
		return;
	}
	if(sum>2) return;
	for(int i=ed;i>w;i--){
		if(x[i]-x[w]<=d){
			dfs(i,ed,li+1);
		}
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
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				sum=0;
				f=1;
				dfs(i,j,0);
				if(sum==2){
					ans++;
//					cout<<i<<" "<<j<<endl;
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 
