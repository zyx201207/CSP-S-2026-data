#include <bits/stdc++.h>
using namespace std;

int n,m,a[10090];
int flag[10009][10009],s[10909];
struct node{
	int cnt,l[10090];
}f[10090];

signed main(){

	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
	
		cin>>a[i];
		
		f[a[i]].cnt++;
		f[a[i]].l[f[a[i]].cnt]=i;
	
	}
	
	int g[100090],v[10090],r=0;
	
	for(int i=1;i<=n;i++){
	
		for(int j=1;j<=n;j++){
	
			g[i]=0;
			v[i]=a[i];
	
		}
		
		for(int j=i;j<=n;j++){
			
			r++;
			
			if(g[a[j]]){
		
				for(int d=1;d<=f[a[j]].cnt;d++){
					
					if(f[a[j]].l[d]>=i){
								
						r=f[a[j]].l[d];
						//r--;
		
					}
		
				}
		
			}else{
		
				g[a[j]]++;	
		
			}
		
		}
		
		for(int j=i;j<=r;j++){
			s[j]++;
		}
		
	}
		
	for(int i=1;i<=m;i++){
		cout<<s[i]<<' ';
	}
		
		
	return 0;
} 
