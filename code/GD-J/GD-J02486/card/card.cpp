#include<bits/stdc++.h>
using namespace std;
int n,m,arr1[200010],step[200010];
int check(int a,int b){
	for(int i = 1;i<=b;i++){
		if(arr1[i]==a) return 1;
	}
	return 0;
}
int main(){
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>arr1[i];
	}
	int num=0;
	queue<int> q;
	for(int i = 1;i<=n;i++){
		for(int j = i;j<=n;j++){
			if(check(arr1[j],j-1)==1){
				for(int k = 1;k<=q.size();k++){
					q.pop();
				}
			}
			q.push(arr1[j]);
		}
		while(!q.empty()){
			int a=q.front();
			step[a]++;
			q.pop();
		}
	}
	for(int i = 1;i<=m;i++){
		cout<<step[i]<<" ";
	}
	return 0;
} 
