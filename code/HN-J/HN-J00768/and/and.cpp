#include <bits/stdc++.h>
using namespace std;
long long a[200005],n,m,maxn=0;
long long dfs(int n){
	for(int i=1;i<=n;i++){
		maxn=max(maxn,a[i]&a[i+1]);
		
	}
	return maxn;
}
int main(){
    
    cin>>n>>m;
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
    for(int i=1;i<=n;i++){
        
        cin>>a[i];
        
    }
    cout<<dfs(n);
   
    return 0;
}
