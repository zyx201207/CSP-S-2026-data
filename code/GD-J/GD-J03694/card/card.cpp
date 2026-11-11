#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[50010],b[50010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 0;i<n;++i){
		cin>>a[i];	
	}
	for(int i = 0;i<n;++i){
		long long g[50010]={};
		bool f[50010]={};
		for(int j = 0;j<n;++j){
			if(f[a[j]]){
				f[a[j]]=false;
				for(int k = 0;k<j;++k){
					if(g[k])b[g[k]]--;	
					g[k]=0;
				}
			} 
			else{
				f[a[j]]=true;
				g[j]=a[j];
				b[a[j]]++;
			}
		}
	}
	for(int i = 1;i<= m;++i)cout<<b[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
