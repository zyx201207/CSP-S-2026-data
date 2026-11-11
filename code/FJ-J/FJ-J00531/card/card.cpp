#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,m,a[1000000],ans[1000000];
	stack<long long>q;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i]; 
	for(int i=1;i<=n;i++){
		long long t[1000000]={0},m=0;
		for(int j=i;j<=n;j++){
			q.push(a[i]);
			m++;
			if(t[a[i]]==0)t[a[i]]=m;
			else{
				for(int k=m;k>=t[a[i]];k--){
					if(t[q.top()]>t[a[i]])t[q.top()]=0;
					q.pop();
				}
			}	
		}
		while(!q.empty()){
			ans[q.top()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i];
	return 0;
}
