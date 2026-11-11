#include<bits/stdc++.h>
using namespace std;
int a[500005][500005],b[500005][500005];
int card(int x,int g){
	int c=0,t=0;
    	for(int i=1;i+x-1<=g;i++){
    		for(int j=1;j+x-1<=g;i++){
    			  if(a[x][i]==b[x][j]){
    			  	for(int l=j;l<=g;l++){
    			  		b[x][j]=0;
					}
					b[x][j]=a[x][i];
					c++;
				}
			}
			if(!c){
				b[x][i+1]=a[x][i];
			}
		}
		for(int i=1;i<=g;i++){
			if(b[x][i]==x){
				t++;
			}
		}
		return t;
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[1][i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			a[i][j]=a[1][j];
		}
	}
	for(int i=1;i<=n;i++){
		cout<<card(i,m)<<" ";
	}
	return 0;
}       //¸ñµ÷                                                                    
                                                                             
