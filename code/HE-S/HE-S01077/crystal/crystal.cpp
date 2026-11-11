#include<bits/stdc++.h>
using namespace std;
int n,m,mmax=INT_MIN,a[500002];
bool tong[500002];
void dfs(int step,vector<int> caozuo,int start){
	if(step>m) return;
	if(step<=m){
		mmax=max((int)caozuo.size(),mmax);
	}
	int zuida=INT_MIN;
	for(int i=0;i<caozuo.size();i++){
		zuida=max(zuida,caozuo[i]);
		//cout<<caozuo[i]<<" ";
	}
	for(int i=0;i<caozuo.size();i++){
		step+=zuida-caozuo[i];
	}
	//cout<<step<<endl;
	for(int i=start;i<n;i++){
		if(!tong[i]){
			tong[i]=1;
			caozuo.push_back(a[i]);
			dfs(step,caozuo,start+1);
			caozuo.pop_back();
			tong[i]=0;
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	vector<int> caozuo;
	dfs(0,caozuo,0);
	cout<<mmax;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
