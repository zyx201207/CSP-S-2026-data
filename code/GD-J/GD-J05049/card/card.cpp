#include<bits/stdc++.h>
using namespace std;
int n,m,a[500007],b[500007],sum[100007],ans[100007];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= n; i ++){
    	cin>>a[i];
	}
    for(int i = 1; i <= n; i ++){
    	for(int j = 1; j <= m; j ++){
    		sum[j] = 0;
		}
    	for(int j = i; j <= n; j ++){
    		b[j] = a[j];
    		sum[b[j]]++;
    		if(sum[b[j]]>=2){
    		   sum[b[j]] = 0;
    		   for(int x = j-1;x >= i;x --){
    		   	   if(b[x] == b[j]){
    		   	   	b[x] = -1;
    		   	   	break;
				  }
				  b[x] = -1;
			   }
			}
		}
		for(int x = 1; x <= m; x ++){
			for(int j = i; j <= n; j ++){
				if(b[j]==-1){
					continue;
				}
				if(b[j] == x){
				   ans[x]++;
				   break;	
				}
			}
		}
	}
	for(int i = 1; i <= m; i ++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

