#include <bits/stdc++.h>
using namespace std;

int a[200005];
int v[200005]={0};
int xuan[200005];
int nmin=0;
int num;
void dfs(int step,int start){
	if(step==m){
		for(int i=0;i<m;i+=2){
			num=m[i]&m[i+1];
		}
		if(nmin<=num){
			cout << nmin;
			return;
		}
	}
	for(int i=0;i<n;i++){
		if(v[i]==0){
			v[i]==1;
			m[i]==a[i];
		}
		dfs(1+i,1=1)
	}
	
		
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >>m;
	for(int i=0;i<n;i++){
		cin >> a[i];
		dfs(0,0);
		cout << 
	}
	
	
	return 0;
}
