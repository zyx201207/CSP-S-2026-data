#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=5e5+10,M=3e5+10;
int a[N],ans[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	//queue<int> q;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		bool vis[m+10];
		memset(vis,0,sizeof(vis));
		//while(!q.empty()) q.pop();
		int l=i;
		//cout<<i<<":"<<endl;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				//cout<<i<<": ";
				int f=0,k1=0;
				for(int k=l;k<j;k++){
					if(a[k]==a[j]) f=1;
					if(f==1){
						vis[a[k]]=0;
						k1++;
					}
				}
				if(k1>=m) l=j;
			}
			//q.push(a[j]); 
			vis[a[j]]=1;
			

//			for(int i=1;i<=m;i++)
//				cout<<vis[i]<<" ";
//			cout<<endl;
		}
		//cout<<endl;
		for(int i=1;i<=m;i++){
			if(vis[i]){
				//cout<<i<<" ";
				ans[i]++;
			}
		}
		//cout<<endl<<endl;
	}
	//cout<<endl;
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}

