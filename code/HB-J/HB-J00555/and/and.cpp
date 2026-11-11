#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m;
long long a[N];
long long maxx=-1;
int step=0;
void dfs(int k){
	 if(step>=n)return ;
	 if(m==2){
		 for(step=k+1;step<n;step++){
		     maxx=max(maxx,a[k]&a[step]);
	     }
     } else if(m==1){
		 for(int i=0;i<n;i++){
			 maxx=max(maxx,a[i]);
		 }
	 } else if(m==n){
		 for(int i=0;i<m;i++){
		     maxx=maxx&a[i];			
		 }
	 } else if(m==3){
		 for(step=k;step<n;step++){
			 for(int j=k+1;j<n;j++){
				 for(int ym=k+2;ym<n;ym++){
					 if(a[step]!=a[j]&&a[j]!=a[ym]&&a[step]!=a[ym])maxx=max(maxx,a[step]&a[j]&a[ym]);
				 }
			 }
		 }
	 }
	 step=k;
	 dfs(step+1);
	 dfs(step+2);
	 
	 
	 
	
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dfs(0);
	cout<<maxx;
	return 0;
}
