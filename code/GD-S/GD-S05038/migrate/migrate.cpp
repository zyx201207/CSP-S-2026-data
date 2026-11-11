#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=5e3+10;

int c,T;
int n;
ll d,a[M];
int far[M],md[M][M],ok[M][M];
int ans;

void init(){
	for(int i=1;i<=n;i++){
		a[i]=0;
		for(int j=i;j<=n;j++)md[i][j]=ok[i][j]=0;
	}
	ans=0;
}

void dfs(int sta,int u,int k){
//	cout<<":"<<u<<' '<<k<<endl;
	if(k==md[sta][u])ok[sta][u]++;
	for(int i=u+1;i<=far[u];i++){
		dfs(sta,i,k+1);
	}
	
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
	
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)far[i]=i;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=d){
				far[i]=j;
			}
			else{
				break;
			}
		}
	}
//	for(int i=1;i<=n;i++)cout<<i<<' '<<far[i]<<endl;
//	cout<<endl;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			int cnt=0;
			int ti=i;
			while(ti<j){
				if(ti==far[ti])break;
				ti=far[ti];
				cnt++;
			}
			md[i][j]=cnt;
		}
	}
//	for(int i=1;i<n;i++){
//		for(int j=i+1;j<=n;j++){
//			cout<<md[i][j]<<' '; 
//		}
//		cout<<endl;
//	}
	for(int i=1;i<n;i++){
		dfs(i,i,0);
//		cout<<"/////////////////////"<<endl;
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(ok[i][j]==2){
				ans++;
//				cout<<i<<' '<<j<<endl;
			}
		}
	}
	cout<<ans<<endl;
//	cout<<"----------------------------------"<<endl;
	init();
	
	}
} 
