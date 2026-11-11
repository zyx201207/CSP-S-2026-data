#include<iostream>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;

int maxx = -1;
int que[200010];
int n,m,k=0;
int arr[200010];
int vis[200010];
void dfs(int x){
	k++;
	que[k]=x;
	if(k==m){
		int sum = que[1];
		for (int i = 2 ; i <= k ; i++){
			int y=que[i];
			sum = sum&y;
		}
		if(maxx < sum) maxx = sum;
		return;
	} 
	for (int i = 1 ; i <= n ; i++){
		if(vis[i]==0){
			vis[i]==1;
			dfs(i);
			vis[i]==0;
		}
	}
}

int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++){
		cin >> arr[i];		
	}
	
	for (int i = 1 ; i <= n ; i++){
		vis[i]=1;
		dfs[arr[i]];
		vis[i]=0;
	}
	cout << maxx;
	return  0;
} 
