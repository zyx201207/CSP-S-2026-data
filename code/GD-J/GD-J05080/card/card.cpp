#include<bits/stdc++.h>
using namespace std;
long long ans[300009];
long long n,m;
stack<long long> k;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	cin>>n>>m;
	long long a[n+1]={};
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
	long long b[m+1]={};
	for(long long j=i;j<=n;j++){
		if(b[a[j]]==0){
			b[a[j]]++;
			k.push(a[j]);
		}
		else{
			long long o=j-1;
			while(a[j]!=a[o]){
				if(a[o]==k.top()){
					k.pop();
					b[a[o]]--;
				}
				o--;
			}
			
		}
	}
	for(long long j=1;j<=m;j++){
		if(b[j]!=0){
			ans[j]++;
		}
	}
	}
	for(long long i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
