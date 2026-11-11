#include<iostream>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	if(n<=500 && m<=200){
		int a[510],t[210]={0};
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			bool k[210];
			for(int p=1;p<=m;p++) k[p]=1;
			for(int j=i;j<=n;j++){
				bool vis[210]={0},flag=1;
				for(int o=i;o<j;o++) vis[a[o]]=1;
				for(int o=j+1;o<=n;o++){
					if(vis[a[o]]==1){
						flag=0;
						break;
					}
				}
				if(flag && k[a[j]]) t[a[j]]++,k[a[j]]=0;
			}
		}
		for(int i=1;i<=m;i++) cout<<t[i]<<' ';
		return 0;
	}
	int a[n+10],t[m+10];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<' ';
	}
	return 0;
}
//rp++
//wo neng shang mi huo xing wei da shang ma 
