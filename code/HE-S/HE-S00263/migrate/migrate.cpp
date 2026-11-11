#include<bits/stdc++.h> 
using namespace std;
int n,d,c1,t,num=0;
int b[2000005],c[2000005];
vector<int> a[2000005];
int dfs(int ans,int i,int p){
	if(i==p){
		num++;
		return 1;
	}
	for(int j=1;j<=b[i];j++){
		dfs(++ans,a[i][j],p);
	}return num;	
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c1>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>b[i];
		}
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(b[k]-b[j]<=d){
					a[j].push_back(k);
					c[j]++;
				}
			}
		}for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				num=0;
				if(dfs(1,i,j)==2)
					b[i]++;
			}
		}
	}
	for(int i=1;i<=t;i++){
		cout<<b[i]<<" ";
	}return 0;
}
