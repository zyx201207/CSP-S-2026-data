#include<bits/stdc++.h>
using namespace std;
int r=1,l=1;
int n,m,a[500005],vis[300005],zhai[500005];
int main(){
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        zhai[r]=a[i];
        
        for(int j=1;j<=i;j++){
            if(zhai[j]==zhai[r]){
                zhai[j]=zhai[r];
                r=j;
                
                break;
            }
        }
        
        for(int j=i;j<=n;j++){
			
            vis[a[j]]++;
        }
        
        r++;
    }
    for(int i=1;i<=m;i++){
		cout<<vis[i]<<" ";
	}
        
    return 0;
}
