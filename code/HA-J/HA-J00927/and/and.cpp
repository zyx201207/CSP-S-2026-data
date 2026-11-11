#include<bits/stdc++.h>
using namespace std;
bool b[200001];
int m,n,a[200001];
int func(int o,int p){
	string o1,p1;
	while(o){
		o1+=o%2+'0';
		o/=2;
	}
	while(p){
		p1+=p%2+'0';
		p/=2;
	}
	int Min;
	Min=o1.size()-1;
	if(Min<p1.size()-1){
		Min=p1.size()-1;
	}
	int u=0;
	for(int i=0;i<=Min;i++){
		if(o1[i]=='1'&&p1[i]=='1'){
			u+=pow(2,i);
		}
	}
	return u;
}
bool flag;
void dfs(int i,int ans){
	if(i==n&&flag!=1){
		cout<<ans;
		flag=1;
	}else{
		int last=-1;
		int Max=-1;
		for(int j=1;j<=n;j++){
			if(b[j]==0){
				if(Max<func(ans,a[j])){
					Max=func(ans,a[j]);
					b[j]=1;
					b[last]=0;
					last=j;
				}
			}
		}
		dfs(i+1,Max);
	}
}
int main(){
	
	
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	} 
	dfs(0,0);
}

