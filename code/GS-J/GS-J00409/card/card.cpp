#include<bits/stdc++.h>
using namespace std;
int n,a[10010],m;
int c[10010],sum[10010],q[10010];
void game(int p){
	stack <int> b;
	int t;
	for(int i=p;i<=n;i++){
		b.push(a[i]);
		for(int j=1;j<=b.size();j++){
			if(c[j]==a[i]){
				for(int k=j;k<=b.size();k++){
					b.pop();
				}
				continue;
			}
		}
		t=b.size();
		c[t]=a[i];	
}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q[i]=a[i];
	}
	sort(q+1,q+n+1);
	for(int i=1;i<=n;i++){
		game(i);
		for(int v=1;v<=n;v++){
			for(int x=1;x<=n;x++){
			if(a[x]==c[v]){
				sum[x]++;
				c[v]=0;
				}
			}
		} 
	}
	sum[n-1]=sum[n];
		for(int i=1;i<=m;i++){
			cout<<sum[i]<<" ";
		}
	}	
		 
	
