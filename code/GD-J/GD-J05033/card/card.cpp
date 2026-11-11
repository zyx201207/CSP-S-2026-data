#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,ans[N],vis[N],shan[N];
int a[N];
bool ff=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])ff=0;
	}
	if(n<=500){
		for(int i=1;i<=n;i++){
			stack<int> s;
			for(int j=i;j<=n;j++){
				bool f=0;
				for(int k=j-1;k>=i;k--){
					if(a[k]==a[j]&&shan[k]==0){
						f=1;
					}
				}
				if(f){
					while(!s.empty()){
						int t=s.top();
						s.pop();
						shan[t]=1;
						if(a[t]==a[j])break;
					}
				}
				s.push(j);
			}
			while(!s.empty()){
				int t=s.top();
				s.pop();
				if(!vis[a[t]]){
					vis[a[t]]=1;
					ans[a[t]]++;
				}
			}
			for(int j=1;j<=m;j++)vis[j]=0;
			for(int j=1;j<=n;j++)shan[j]=0;
		}
	}
	else if(ff){
		for(int i=1;i<=n;i++){
			ans[a[i]]=i;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
//	cout<<ans;
	return 0;
}
