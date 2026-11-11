#include<bits/stdc++.h>
using namespace std;
long long m,n,a[200005],ans[10000],b[200005];
int dfs(int x,int y){
	for(int f =0;f<y-1;f++){
		for(int h =y+1;f<n;f++){
			if(a[f]==a[h])x--;
		}
	}
	return x;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		b[i] =a[i];
	}
	if(m==1){
		cout<<n;
		return 0;
	}
    if(n==m){
    	for(int i=0;i<n;i++){
    		cout<<i+1<<" ";
		}
		return 0;
	}
	sort(b,b+n);
	int nom =unique(b,b+n)-b;
	for(int i=0;i<n;i++){
		    
		    ans[a[i]]=ans[a[i]]+dfs(i+1,i);
		}
		cout<<ans[nom-2]<<" ";
		for(int i=0;i<nom-1;i++){
		  
    		cout<<ans[i]+1<<" ";
		}
	
	return 0;
} 
