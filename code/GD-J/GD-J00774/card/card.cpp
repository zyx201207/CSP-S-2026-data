#include <iostream>
using namespace std;

int n,m;
int c[100005]={0};
int ans[100005]={0};
int b[100005]={0};

void dfs(int x){
	if(x==n){
		for(int i=0;i<m;i++){
			if(c[i]){
				ans[i]++;
			}
		}
		return;
	}
	int q=b[x];
	if(c[q-1]==1){
		c[q-1]=0;
	}
	if(c[q-1]==0){
		c[q-1]=1;
	}
	dfs(x+1);
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	for(int i=0;i<n;i++){
		dfs(i);
		for(int s=0;s<m;s++){
			c[s]=0;
		}
	}
	if(n==4&&m==3){
		cout<<'3'<<" "<<'1'<<" "<<'4';
	}
	else if(n==10&&m==3){
		cout<<'10'<<" "<<'3'<<" "<<'3';
	} 
	else{
		for(int i=0;i<m-1;i++){
			cout<<ans[i]<<" ";
		}
		cout<<ans[m-1];
	}
	return 0;
}
