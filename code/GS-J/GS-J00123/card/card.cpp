#include<iostream>
#include<cstdio>
#include<cstring>
    int main{
    	freopen("card.in","r",stdin);
	    freopen("card.out","w",stdout);
	    int n,m;
	    int a[n][m];
	    for(int i=0;i<n;i++){
	    	cin>>a[i][m];
	    	for(int j=0;j<m;j++){
	    		cin>>a[n][j];
			}
	    }
	    int b[z];
	    for(int h=0;h<n;h++){
	    	b[h]=a[h][0];
	    	for(int g=0;g<m;g++){
	    		b[h*n+g]=a[h][g];
			}
		}
		for(int s=0;s<n*m;s++){
			for(int d=0;d<n*m;d++){
				if(b[s]==b[d]&&s!=d){
					b[d]=o;
				}
			}
		}
    	return 0;
	}
