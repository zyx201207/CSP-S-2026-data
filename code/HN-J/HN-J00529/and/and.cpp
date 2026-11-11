#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[200001];
	int k=0;
	vector<int>v[40];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		k=a[i];
		for(int j=0;k;j++){
			if(k%2)v[j].push_back(i);
			k/=2;
		}
	}int sum=0;
	bool vis[200001]={};
	for(int i=32;i>=0;i--){
		if(v[i].size()>=m){
			for(int j=0;j<v[i].size();j++){
				vis[v[i][j]]=1;
			}
			sum+=1<<i;
			k=i;
			break;
		}
	}int h,t=0;
	int mo[200001]={},stp;
	for(int i=k-1;i>=0;i--){
		h=0,stp=0;
		for(int j=1;j<=n;j++){
			if((a[j]&(1<<i))&&vis[j]==1){
				h++;
			}else if(vis[j]==1){
				mo[++stp]=j;
			}
		}
		if(h>=m){
			sum+=1<<i;
			for(int j=1;j<=stp;j++)vis[mo[j]]=0;
		}
	}cout<<sum;
	return 0;
}
