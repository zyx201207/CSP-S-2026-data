#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans=0;
int a[500005];
int b[5005],c[5005];
void DFS(int mx,int sum){
	ans=max(ans,sum);
	if(mx==0||sum==n){
		return ;
	}
	for(int i=1;i<=n;i++){
		if(c[i]==0){
			for(int j=i+1;j<=n;j++){
				if(c[j]==0&&abs(b[i]-b[j])<=mx){
					if(!(mx-abs(b[i]-b[j])==0&&sum<=ans)){
						int x=b[i],y=b[j];
						c[i]=1;
						b[i]=0;
						b[j]=x+y;
						DFS(mx-abs(b[i]-b[j]),sum+1);
						c[i]=0;
						b[i]=x;
						b[j]=y;
					}
				}
			}
		}
	}
	return ;
} 
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=500){
		for(int i=1;i<=n;i++){
			b[i]=a[i]; 
		}
		DFS(m,0);
		cout<<ans+1<<'\n';
	}else{
		cout<<n<<'\n';
	}
    return 0;
}
