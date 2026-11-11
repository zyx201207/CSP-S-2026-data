#include<bits/stdc++.h> 
using namespace std;
long long n,m,i,a[200005],b[200005],ans[200005],k[200005]; 
int main(){
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(k[b[a[i]]]==0){
			k[b[a[i]]]=i;
			//k[i]:下一个a[i]的位置 
		}
		b[a[i]]=i;
		//记a[i]的位置 
	}
	for(i=1;i<=m;i++)ans[i]=0;
	for(i=1;i<=n;i++){
		long long w=i;
		//位置 
		while(w<=n){
			if(k[w]!=0){
				w=k[w];
			}else{
				//证明后面已无a[w],图：a[w]... 
				ans[a[w]]++;
				w++;
			}
		}
	}
	for(i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	} 
	return 0;
} 
