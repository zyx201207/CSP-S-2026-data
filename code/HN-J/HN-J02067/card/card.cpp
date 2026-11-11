#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	queue<long long> a;
	long long n,m;
	cin>>n>>m;
	long long b[n],ans[m]={0},c[m]={0};
	for(long long i=0;i<n;i++){
		cin>>b[i];
	}
	for(int j=0;j<m;j++){
		c[m]={0};
		for(long long i=0;i<n;i++){
			c[b[i]]+=1;
			if(c[b[i]]!=1 &&c[b[i]]!=0){
				while(!a.empty()){
					a.pop();
				}
			}a.push(b[i]);
		}
		while(!a.empty()){
			ans[a.front()]++;
			a.pop();
		}		
	}
	for(int i=1;i<m+1;i++){
		cout<<ans[i]<<" ";
	}
	return 0; 
} 
