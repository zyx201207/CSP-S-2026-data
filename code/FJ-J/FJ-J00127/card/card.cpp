#include <bits/stdc++.h>
using namespace std;
long long a[500005],tong[300005],datong[300005];
int main(){
	freopen("card.in","r",stdio);
	freopen("card.out","w",stdio);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		stack<int> q;
		for(int j=i;j<=n;j++){
			if(tong[a[j]]==0){
				q.push(a[j]);
				tong[a[j]]=1;
			}else{
				while(!q.empty()&&q.top()!=tong[a[j]]){
					q.pop();
				}
			}
		}
		while(!q.empty()){
			datong[q.top()]++;
			q.pop();
		}
		memset(tong,0,300005);
	}
	for(int i=1;i<=m;i++){
		cout<<datong[i]<<" ";
	}
	return 0;
} 

